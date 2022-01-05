/*******************************************************************************
*       Fichier            : Statut_Unit.cpp                                   *
*       Projet             : ZM Programs Protector                             *
*       Programmeur        : ZAGANE Mohammed                                   *
*       Email              : m_zagane@yahoo.fr                                 *
*       site web           : http://mzagane.webou.net                          *
*       Date source        : lundi 09 février 2009                             *
*       Version source     : 1.04.02.2012                                      *
*       Langage            : Borland C++ Builder version 6                     *
*       Type licence       : GNU GPL                                           *
*       Modification       : Samedi 04/02/2012                                 *
*******************************************************************************/
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Statut_Unit.h"
#include "Main_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TStatut_Form *Statut_Form;
//---------------------------------------------------------------------------
__fastcall TStatut_Form::TStatut_Form(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TStatut_Form::Cancel_SpeedButtonClick(TObject *Sender)
{
        Main_Form->Treatment_Canceled = true;
        Main_Form->Enabled = true;
        Close();
}
//---------------------------------------------------------------------------

