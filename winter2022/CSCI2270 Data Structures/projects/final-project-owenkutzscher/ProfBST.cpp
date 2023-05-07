//-----------------------------------------------------------------------------
// CSCI2270 Course Project
//
// Identification: ProfBST.cpp
//-----------------------------------------------------------------------------

#include "ProfBST.h"

#include <iostream>

using namespace std;


/**********************************************************
 * COMMENTING SECTION
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *********************************************************
 */










/**
 * ProfBST - creates the root of a Professor BST
 **/
ProfBST::ProfBST()
{
    root = nullptr;
}

/**
 * destroyNode - recursively deletes all nodes in a Professor BST
 * 
 * @param s
 **/
void destroyNode(Professor *s)
{
    // aight how we gon do this?
    // HERES HOW WE GON DO THIS, DALE -Pitbull
    // post order traversal4
    if(s)       // same as if s!= NULL
    {
        destroyNode(s -> left);
        destroyNode(s -> right);
        
        Course *c = nullptr;
        for(int i=0; i<s->coursesTaught.size(); i++)
        {
            if(c)
            {
                delete c;
                c = nullptr;
            }
        }

        delete s;
        s = nullptr;
    }
}

/**
 * ~ProfBST - frees all memory allocated to a Professor BST
 **/
ProfBST::~ProfBST()
{
    destroyNode(root);
}

/**
 * addProfessorHelper - find place for and inserts a new professor into the Professor BST
 * 
 * @param s
 * @param profID
 * @param profName
 * @return Professor*
 **/
Professor* addProfessorHelper(Professor *s, string profID, string profName)
{
    if(s)
        if(s->profId == profID)     // dont allow duplicates to be inserted
            return s;

    if(s == nullptr){
        Professor *owen = new Professor(profID, profName);
        return owen;
    }

    else if(s -> profId>profID)     // left
        s -> left = addProfessorHelper(s -> left, profID, profName);
    else if(s->profId<profID)     // right
        s -> right = addProfessorHelper(s -> right, profID, profName);

    return s;
}

/**
 * addProfessor - inserts a new professor into BST
 * 
 * @param profId
 * @param profName
 **/
void ProfBST::addProfessor(string profId, string profName)
{
    root = addProfessorHelper(root, profId, profName);
}








/**
 * searchProfessorHelper - finds and returns a specific Professor in BST
 * 
 * @param s
 * @param profId
 * @return Professor*
 **/
Professor *searchProfessorHelper(Professor *s, string profId)
{
    if (!s)
        cout << "Professor not found" << endl;
    else if (s->profId == profId){
        // cout << "returning: " << s->profId << endl;
        return s;
    }
    else if (s->profId > profId)      // left
        return searchProfessorHelper(s -> left, profId);
    else if (s->profId < profId)      // right
        return searchProfessorHelper(s -> right, profId);
    return nullptr;
}


/**
 * searchProfessorHelper - finds and returns a specific Professor in BST
 * 
 * @param profId
 * @return Professor*
 **/
Professor* ProfBST::searchProfessor(string profId)
{
    return searchProfessorHelper(root, profId);
}










/**
 * publicSearchProfessor - finds a Professor and displays Professor's info
 * 
 * @param s
 * @param profId
 * @return Professor*
 */
Professor *publicSearchProfessorHelper(Professor *s, string profId)
{
    if (!s)
        cout << "Professor not found" << endl;
    else if (s->profId == profId){
        // cout << "returning: " << s->profId << endl;
        return s;
    }  
    else if (s->profId > profId)      // left
        return searchProfessorHelper(s -> left, profId);
    else if (s->profId < profId)      // right
        return searchProfessorHelper(s -> right, profId);
    return nullptr;
}

/**
 * publicSearchProfessor - finds a Professor and displays Professor's info
 * 
 * @param profId
 */
void ProfBST::publicSearchProfessor(string profId)
{
    Professor *p = publicSearchProfessorHelper(root, profId);

    if(!p)
        cout << "Professor not found" << endl;
    else
    {
        cout << "Name: " << p->profName << endl;
        displayProfessorInfo(p);
    }  
}




/**
 * displayProfessorInfo - prints to terminal info contained in a Professor
 * 
 * @param p
 */
void ProfBST::displayProfessorInfo(Professor* p)
{
    Course *c = nullptr;
    for(int i=0; i<p->coursesTaught.size(); i++)
    {
        c = p->coursesTaught[i];
        cout << "- " << c->courseNum << ": " << c->courseName << ", " << c->year << endl;
    }
}
