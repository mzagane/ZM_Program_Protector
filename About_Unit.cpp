/*******************************************************************************
*       Fichier            : Abou_Unit.cpp                                     *
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

#include "About_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAbout_Form *About_Form;
//---------------------------------------------------------------------------
__fastcall TAbout_Form::TAbout_Form(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAbout_Form::Web_Site_LabelClick(TObject *Sender)
{
        ShellExecute(0,"open","http://mzagane.webou.net",0,0,SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------
void __fastcall TAbout_Form::Label7Click(TObject *Sender)
{
        ShellExecute(0,"open","mailto:m_zagane@yahoo.fr",0,0,SW_SHOWNORMAL);                
}
//---------------------------------------------------------------------------
void __fastcall TAbout_Form::Ok_SpeedButtonClick(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------
