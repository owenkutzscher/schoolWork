// 
// tsh - A tiny shell program with job control
// 
// <Put your name and login ID here>
//

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string>

#include "globals.h"
#include "jobs.h"
#include "helper-routines.h"

//
// Needed global variable definitions
//

static char prompt[] = "tsh> ";
int verbose = 0;

//
// You need to implement the functions eval, builtin_cmd, do_bgfg,
// waitfg, sigchld_handler, sigstp_handler, sigint_handler
//
// The code below provides the "prototypes" for those functions
// so that earlier code can refer to them. You need to fill in the
// function bodies below.
// 

void eval(char *cmdline);
int builtin_cmd(char **argv);
void do_bgfg(char **argv);
void waitfg(pid_t pid);

void sigchld_handler(int sig);
void sigtstp_handler(int sig);
void sigint_handler(int sig);

//
// main - The shell's main routine 
//
int main(int argc, char **argv) 
{
  int emit_prompt = 1; // emit prompt (default)

  //
  // Redirect stderr to stdout (so that driver will get all output
  // on the pipe connected to stdout)
  //
  dup2(1, 2);

  /* Parse the command line */
  char c;
  while ((c = getopt(argc, argv, "hvp")) != EOF) {
    switch (c) {
    case 'h':             // print help message
      usage();
      break;
    case 'v':             // emit additional diagnostic info
      verbose = 1;
      break;
    case 'p':             // don't print a prompt
      emit_prompt = 0;  // handy for automatic testing
      break;
    default:
      usage();
    }
  }

  //
  // Install the signal handlers
  //

  //
  // These are the ones you will need to implement
  //
  Signal(SIGINT,  sigint_handler);   // ctrl-c
  Signal(SIGTSTP, sigtstp_handler);  // ctrl-z
  Signal(SIGCHLD, sigchld_handler);  // Terminated or stopped child

  //
  // This one provides a clean way to kill the shell
  //
  Signal(SIGQUIT, sigquit_handler); 

  //
  // Initialize the job list
  //
  initjobs(jobs);

  //
  // Execute the shell's read/eval loop
  //
  for(;;) {
    //
    // Read command line
    //
    if (emit_prompt) {
      printf("%s", prompt);
      fflush(stdout);
    }

    char cmdline[MAXLINE];

    if ((fgets(cmdline, MAXLINE, stdin) == NULL) && ferror(stdin)) {
      app_error("fgets error");
    }
    //
    // End of file? (did user type ctrl-d?)
    //
    if (feof(stdin)) {
      fflush(stdout);
      exit(0);
    }

    //
    // Evaluate command line
    //
    eval(cmdline);
    fflush(stdout);
    fflush(stdout);
  } 

  exit(0); //control never reaches here
}
  
/////////////////////////////////////////////////////////////////////////////
//
// eval - Evaluate the command line that the user has just typed in
// 
// If the user has requested a built-in command (quit, jobs, bg or fg)
// then execute it immediately. Otherwise, fork a child process and
// run the job in the context of the child. If the job is running in
// the foreground, wait for it to terminate and then return.  Note:
// each child process must have a unique process group ID so that our
// background children don't receive SIGINT (SIGTSTP) from the kernel
// when we type ctrl-c (ctrl-z) at the keyboard.
//
void eval(char *cmdline) 
{
  /* Parse command line */
  //
  // The 'argv' vector is filled in by the parseline
  // routine below. It provides the arguments needed
  // for the execve() routine, which you'll need to
  // use below to launch a process.
  //
  char *argv[MAXARGS];

  //
  // The 'bg' variable is TRUE if the job should run
  // in background mode or FALSE if it should run in FG
  //
  int bg = parseline(cmdline, argv);  // splits the input: "sleep 30 &" -> ["sleep","30"]
                                        // bg is positivie if & is there, 0 otherwise
    
    // need to block incase a ctrl c is called right after a thing is called
    // we will unblock later...
    // do stuff with a mask
    
    
    
  if (argv[0] == NULL)  
    return;   /* ignore empty lines */
    else if(!builtin_cmd(argv)){  // the builtin_cmd runs the builtin cmd automaticlly if it is one
        
        
        // build the mask
        // blocks the signal immediatly
        sigset_t sigsetMask;
        sigemptyset(&sigsetMask);
        sigaddset(&sigsetMask, SIGCHLD);
        sigaddset(&sigsetMask, SIGINT);
        sigaddset(&sigsetMask, SIGTSTP);
                    
        
        
        
        
        // 1a.
        pid_t pid = fork();
        
        // 1b. make child do this stuff
        // child is seperate from parent, parent controls job list and stuff like that
        if(pid == 0){
            //sigprocmask(SIG_UNBLOCK, &sigsetMask, NULL);
                
            
            // makes surechild in same group as parent
            // UNBLOCK so it can do its job real quick and weve already added him to jobs list
            // idk unblock somehwere else too ://///////
            setpgid(0,0);
            
            // passing in... name of program, run this!, rest of paramaters, environment variables
            // makes it so child can do stuff
            
            int status = execve(argv[0], argv, environ);
            if(status < 0){
                printf("%s: Command not found\n", argv[0]);
                exit(1); // if it fails, then it didn't run other progran so exit rn!!!

            }
            
           
        }else{
            // everything inside here is parent because not == 0.
            
            
            sigprocmask(SIG_BLOCK, &sigsetMask, NULL);

            if(bg){
                addjob(jobs, pid, BG, cmdline);
            }else{
                addjob(jobs, pid, FG, cmdline);
            }
            sigprocmask(SIG_UNBLOCK, &sigsetMask, NULL);

            
            if(!bg){
                waitfg(pid);
            }else{
                int jid = pid2jid(pid);
                printf("[%d](%d)%s", jid, pid, cmdline);
            }
        }  
        return;
    }
    
    
    
    

  return;
}




/////////////////////////////////////////////////////////////////////////////
//
// builtin_cmd - If the user has typed a built-in command then execute
// it immediately. The command name would be in argv[0] and
// is a C string. We've cast this to a C++ string type to simplify
// string comparisons; however, the do_bgfg routine will need 
// to use the argv array as well to look for a job number.
//
int builtin_cmd(char **argv) 
{
    string cmd(argv[0]);
    
    // we could totally change to  == with strings!!!
    
    // find other builtins in the README.md
    if("quit" == cmd){
        // terminates the shell
        exit(0);
        //return 1;
    }else if ("jobs" == cmd){
        // lists all bg jobs
        listjobs(jobs);
        return 1;
    }else if ("bg" == cmd || "fg" == cmd){
        // /<job/> is a PID or a JID
        // restarts the /<job/> sending it a SIGCONT signal, then runs it in the bg
        do_bgfg(argv);
        return 1;
    }else if("&" == cmd){
        return 1;
    }
    return 0;     /* not a builtin command */
}

/////////////////////////////////////////////////////////////////////////////
//
// do_bgfg - Execute the builtin bg and fg commands
//
void do_bgfg(char **argv) 
{
  struct job_t *jobp=NULL;
  //pid_t pid;
    
  /* Ignore command if no argument */
  if (argv[1] == NULL) {
    printf("%s command requires PID or %%jobid argument\n", argv[0]);
    return;
  }
    
  /* Parse the required PID or %JID arg */
  if (isdigit(argv[1][0])) {
    pid_t pid = atoi(argv[1]);
    if (!(jobp = getjobpid(jobs, pid))) {
      printf("(%d): No such process\n", pid);
      return;
    }
  }
  else if (argv[1][0] == '%') {
    int jid = atoi(&argv[1][1]);
    if (!(jobp = getjobjid(jobs, jid))) {
      printf("%s: No such job\n", argv[1]);
      return;
    }
  }	    
  else {
    printf("%s: argument must be a PID or %%jobid\n", argv[0]);
    return;
  }

  //
  // You need to complete rest. At this point,
  // the variable 'jobp' is the job pointer
  // for the job ID specified as an argument.
  //
  // Your actions will depend on the specified command
  // so we've converted argv[0] to a string (cmd) for
  // your benefit.
  //
  string cmd(argv[0]);
    
  
    
  if("fg" != cmd){
      // currently a fg job running...
      jobp -> state = BG;  
      // could add a cool lil print boii here  '[2] (591) ./myspin 5'
      printf("[%d] (%d) %s", jobp->jid, jobp->pid, jobp->cmdline); // jid, pid, cmd jobp->cmdline
  }else{
      // its a bg job
      //-pid
      kill(-(jobp->pid), SIGCONT); // kill signal (where sending, what we do to it)
      jobp -> state = FG;   // FG is an enum, thing with state = { stuff, stufff... }
      
      waitfg(jobp->pid);  // wait to execute in fg
  }
    
  return;
}

/////////////////////////////////////////////////////////////////////////////
//
// waitfg - Block until process pid is no longer the foreground process
//
void waitfg(pid_t pid)
{
    
    job_t *j = getjobpid(jobs,pid);
    if(!j){
        return;
    }
    while(j->state == FG){
        sleep(1); // wait for the job to finish
    }
    
    
    // while(1){
    //     if(pid != fgpid(jobs)){
    //         break;
    //     }else{
    //         sleep(1);
    //     }
    // }
    
    
    
//     while(pid == fgpid(jobs)){
//         // sleep(0.9);
//         pause();
//     }
    
  return;
}

/////////////////////////////////////////////////////////////////////////////
//
// Signal handlers
//


/////////////////////////////////////////////////////////////////////////////
//
// sigchld_handler - The kernel sends a SIGCHLD to the shell whenever
//     a child job terminates (becomes a zombie), or stops because it
//     received a SIGSTOP or SIGTSTP signal. The handler reaps all
//     available zombie children, but doesn't wait for any other
//     currently running children to terminate.  
//
void sigchld_handler(int sig) 
{
    // sent when child of parent is done running 
    // something is wrong with one of the children (problem child)
    // sooo we have to KILL THE PROBLEM CHILD
    // lmaoooo
    
    int status;
    
    
    // wait will reap a child and return its id
    // -1 says wait on any child until it's finished
    //
    // WNOHANG if child still running, return immediatly
    // WUNTRACED will make it so we don't skip over the "stopped" bois
    // then we will take ALL the problem children, running AND stopped (stopped is techinly running)
    //
    
    pid_t pid;
    
    // return 0 means child still running
    // else it'll return the pid and go into the while loop
    // if its done running (not stopped) then the waitpid is "reaping" the child
    // also ststus is updated by waitpid
    while((pid = waitpid(-1, &status, WNOHANG | WUNTRACED)) > 0){
        // printf("this guys pid is: %d", pid);
        
        // stopped   W IF STOPPED
        // ctrl z
        // or just already stopped in the tree
        if(WIFSTOPPED(status)){
            // 1 get job struct from pid
            // this is from jobs.cc hell yea nice helpers
            // jobs is global variable can find it in header files or something idk
            struct job_t* j = getjobpid(jobs, pid);

            
            // 2
            // 
            j -> state = ST;
            
            // 3
            // now need to print "job [jid] (pid) stopped by signal sig"
            // sig is the int representation of the signal, it was passed origionally :)
            printf("Job [%d] (%d) stopped by signal %d \n", j->jid, pid, WSTOPSIG(status));
        }
        
        // normal exit
        if(WIFEXITED(status)){
            // delete job
            deletejob(jobs, pid);
        }
        
        
        // exit signal (ctrl C)
        if(WIFSIGNALED(status)){
            struct job_t* j = getjobpid(jobs, pid);            
            
            //printf("this guys j id is: %d", j->jid);

            
            printf("Job [%d] (%d) terminated by signal %d \n", j->jid, pid, WTERMSIG(status));
            deletejob(jobs, pid);
        }
        
    }
    
    
    
    
    return;
}

/////////////////////////////////////////////////////////////////////////////
//
// sigint_handler - The kernel sends a SIGINT to the shell whenver the
//    user types ctrl-c at the keyboard.  Catch it and send it along
//    to the foreground job.  
//
void sigint_handler(int sig) 
{
    
    // 1
    // find the fg job running
    
    pid_t pid = fgpid(jobs); // gives the pid of the proscess running in fg, that's the CHILD's pid
    
    
    // PARENT gets all the signals!
    // the "-" sign makes it inteprret it as pid rather than group id (group id is like, all the
    //   parents childrencould be in the group 100 for ex.)
    // eval function will put all the children in the same group or somthing.
    //   They are not there by dafualt tho.
    if(pid > 0){
        // SIGINT is sig
        kill(-pid, sig);
    }
    
    
    // later sigchild_handler will be called so we don't need to delete the job!
  return;
}

/////////////////////////////////////////////////////////////////////////////
//
// sigtstp_handler - The kernel sends a SIGTSTP to the shell whenever
//     the user types ctrl-z at the keyboard. Catch it and suspend the
//     foreground job by sending it a SIGTSTP.  
//
void sigtstp_handler(int sig) 
{
    pid_t pid = fgpid(jobs);
    
        
    // PARENT gets all the signals!
    // the "-" sign makes it inteprret it as pid rather than group id (group id is like, all the
    //   parents childrencould be in the group 100 for ex.)
    // eval function will put all the children in the same group or somthing.
    //   They are not there by dafualt tho.
    
    if(pid > 0){
        // same as above but SIGTSTP instead of SIGINT
        kill(-pid, sig);
    }
    
    
  return;
}

/*********************
 * End signal handlers
 *********************/




