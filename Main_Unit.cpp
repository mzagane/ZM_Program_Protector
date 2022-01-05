/*******************************************************************************
*       Fichier            : Main_Unit.cpp                                     *
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

#include "Main_Unit.h"
#include "Statut_Unit.h"
#include "About_Unit.h"
#include <FileCtrl.hpp> //pour SelectDirectory
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMain_Form *Main_Form;
//---------------------------------------------------------------------------
__fastcall TMain_Form::TMain_Form(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::Brows_SpeedButtonClick(TObject *Sender)
{       
        if(SelectDirectory("Select the basic directory","",Basic_Dir))
        {
                Basic_Dir_Edit->Text = Basic_Dir;
        }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::Add_SpeedButtonClick(TObject *Sender)
{
        if(New_Extension_Edit->Text !="")
        {
                Extension_CheckListBox->Items->Add(New_Extension_Edit->Text);
                New_Extension_Edit->Text = "";
        }

}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::Quit_SpeedButtonClick(TObject *Sender)
{
        Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::Rename_SpeedButtonClick(TObject *Sender)
{

        if(Basic_Dir_Edit->Text =="")
        {
                MessageBox(Handle,"Please select the basic directory","ZM Programs Protector",MB_OK | MB_ICONWARNING);
                return;
        }

        // calculer le nombre d'itèmes cochés
        int Nbr_Checked_Items = 0;
        for(int i=0;i<Extension_CheckListBox->Items->Count;i++)
        {
                if(Extension_CheckListBox->Checked[i])
                {
                       Nbr_Checked_Items ++;
                }
        }
        // fin : calculer le nombre d'itèmes cochés
        
        if(Nbr_Checked_Items == 0 )
        {
                MessageBox(Handle,"Please select the files types to process","ZM Programs Protector",MB_OK | MB_ICONWARNING);
                return;
        }
        //Intialisation
        AnsiString Message = "The program will rename all the files with extension{ ";
        Checked_Extension_StrLst = new TStringList();
        Treatment_Canceled = false;
        Statut_Form->Statut_Label->Caption = "Processing,please wait...";
        if(String_To_Add_Edit->Text !="")
        {
                String_To_Add = String_To_Add_Edit->Text;
        }
        else
        {
                String_To_Add = "ZMPP";
        }
        // fin intialisation

        for(int i=0;i<Extension_CheckListBox->Items->Count;i++)
        {
                if(Extension_CheckListBox->Checked[i])
                {
                       Message = Message + Extension_CheckListBox->Items->Strings[i] +" , ";
                       Checked_Extension_StrLst->Add(Extension_CheckListBox->Items->Strings[i]);
                }
        }

        if( MessageBox(Main_Form->Handle,(Message + "}. Continue?").c_str()
          ,"ZM File protector",MB_YESNO | MB_ICONQUESTION)== IDYES)
        {
                Statut_Form->Show();
                Main_Form->Enabled = false ;

                Rename(Basic_Dir_Edit->Text,Sub_Dirs_CheckBox->Checked);

                delete Checked_Extension_StrLst;
                if(!Treatment_Canceled)
                {
                        Statut_Form->Statut_Label->Caption = "";
                        MessageBox(Handle,"Processing successfly terminated","ZM Programs Protector",MB_OK | MB_ICONINFORMATION);
                }
                else
                {
                        Statut_Form->Statut_Label->Caption = "Processing  canceled";
                }
                Main_Form->Enabled = true ;
                Statut_Form->Close();
        }

}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::Rename(AnsiString Dir, bool Sub_Dirs)
{
        TSearchRec sr;
        AnsiString Path;
        
        if(FindFirst(Dir + "\\*.*", faAnyFile , sr) == 0)
        {
                do
                {
                        if((sr.Attr & faDirectory) == faDirectory)
                        {
                                if(sr.Name !="." && sr.Name!="..")
                                {
                                        if(Sub_Dirs)
                                        {
                                                Rename(Dir+"\\"+sr.Name,Sub_Dirs);
                                                Application->ProcessMessages();
                                        }
                                }
                        }
                        else
                        {
                                //traitement

                                Path = Dir;
                                Path = Path +"\\"+ sr.Name;
                                char drive[_MAX_DRIVE]; // lecteur (c:,d:,...)
                                char _dir[_MAX_DIR];// repertoire
                                char file[_MAX_FNAME];// fichier
                                char ext[_MAX_EXT]; // l'extension
                                _splitpath(Path.c_str(),drive,_dir,file,ext);

                                bool Ext_Exists = false;
                                for(int i = 0 ; i<Checked_Extension_StrLst->Count ; i++)
                                {
                                        if(strcmp(AnsiString(ext).LowerCase().c_str() , ("."+Checked_Extension_StrLst->Strings[i]).LowerCase().c_str()) == 0)
                                        {
                                                Ext_Exists = true;
                                                break;
                                        }
                                        Application->ProcessMessages();
                                }

                                if(Ext_Exists)
                                {
                                        //éliminer les proprietés(fichier caché,fichier système, lecture seule)
                                        AnsiString New_Path = drive;
                                        New_Path = New_Path + _dir;
                                        New_Path = New_Path + file;
                                        New_Path = New_Path + ext;
                                        New_Path = New_Path + String_To_Add;
                                        SetFileAttributes(Path.c_str(),FILE_ATTRIBUTE_NORMAL );
                                        MoveFile(Path.c_str(), New_Path.c_str());
                                        Application->ProcessMessages();
                                }

                        }
                } while (FindNext(sr) == 0 && !Treatment_Canceled);
                FindClose(sr);
        }
}

//---------------------------------------------------------------------------
void __fastcall TMain_Form::Restor(AnsiString Dir, bool Sub_Dirs)
{
        TSearchRec sr;
        if(FindFirst(Dir + "\\*.*", faAnyFile , sr) == 0)
        {
                do
                {
                        if((sr.Attr & faDirectory) == faDirectory)
                        {
                                if(sr.Name !="." && sr.Name!="..")
                                {
                                        if(Sub_Dirs)
                                        {
                                                Restor(Dir+"\\"+sr.Name,Sub_Dirs);
                                                Application->ProcessMessages();
                                        }
                                }
                        }
                        else
                        {
                                //traitement

                                AnsiString Path = Dir;
                                Path = Path +"\\"+ sr.Name;
                                char drive[_MAX_DRIVE]; // lecteur (c:,d:,...)
                                char _dir[_MAX_DIR];// repertoire
                                char file[_MAX_FNAME];// fichier
                                char ext[_MAX_EXT]; // l'extension
                                _splitpath(Path.c_str(),drive,_dir,file,ext);


                                for(int i = 0 ; i<Checked_Extension_StrLst->Count ; i++)
                                {
                                        if(strcmp(AnsiString(ext).LowerCase().c_str() , ("."+Checked_Extension_StrLst->Strings[i]+String_To_Add).LowerCase().c_str()) == 0)
                                        {
                                                SetFileAttributes(Path.c_str(),FILE_ATTRIBUTE_NORMAL );
                                                MoveFile(Path.c_str(),Path.SubString(0,Path.Length() - String_To_Add.Length()).c_str());
                                                break;
                                        }
                                }

                        }
                } while (FindNext(sr) == 0 && !Treatment_Canceled);
                FindClose(sr);
        }
}
void __fastcall TMain_Form::About_LabelClick(TObject *Sender)
{
        //MessageBox(Handle,"*****  ZM Programs Protector v1.12.03.2009  *****\n*  Programmeur : ZAGANE Mohammed                       *\n*  E-mail : zagmoh2005@yahoo.fr                              *\n*  Site web :http://zaagane-mohammed.ifrance.com *\n*******************************************","ZM Programs Protector",MB_OK | MB_ICONINFORMATION);
        About_Form->ShowModal();        
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Restor_SpeedButtonClick(TObject *Sender)
{
        if(Basic_Dir_Edit->Text =="")
        {
                MessageBox(Handle,"Please select the basic directory","ZM Programs Protector",MB_OK | MB_ICONWARNING);
                return;
        }

        // calculer le nombre d'itèmes cochés
        int Nbr_Checked_Items = 0;
        for(int i=0;i<Extension_CheckListBox->Items->Count;i++)
        {
                if(Extension_CheckListBox->Checked[i])
                {
                       Nbr_Checked_Items ++;
                }
        }
        // fin : calculer le nombre d'itèmes cochés
        
        if(Nbr_Checked_Items == 0 )
        {
                MessageBox(Handle,"Please select the files types to process","ZM Programs Protector",MB_OK | MB_ICONWARNING);
                return;
        }
        //Intialisation
        AnsiString Message = "The program will rename all the files with extension : { ";
        Checked_Extension_StrLst = new TStringList();
        Treatment_Canceled = false;
        Statut_Form->Statut_Label->Caption = "Processing, please wait...";
        if(String_To_Add_Edit->Text !="")
        {
                String_To_Add = String_To_Add_Edit->Text;
        }
        else
        {
                String_To_Add = "ZMPP";
        }
        // fin intialisation

        for(int i=0;i<Extension_CheckListBox->Items->Count;i++)
        {
                if(Extension_CheckListBox->Checked[i])
                {
                       Message = Message + Extension_CheckListBox->Items->Strings[i]+String_To_Add+" , ";
                       Checked_Extension_StrLst->Add(Extension_CheckListBox->Items->Strings[i]);
                }
        }

        if( MessageBox(Handle,(Message + "}. Continue ?").c_str()
          ,"ZM File protector",MB_YESNO | MB_ICONQUESTION)== IDYES)
        {
                Statut_Form->Show();
                Main_Form->Enabled = false ;

                Restor(Basic_Dir_Edit->Text,Sub_Dirs_CheckBox->Checked);

                delete Checked_Extension_StrLst;
                if(!Treatment_Canceled)
                {
                        Statut_Form->Statut_Label->Caption = "Processing successfly terminated";
                        MessageBox(Handle,"Processing successfly terminated","ZM Programs Protector",MB_OK | MB_ICONINFORMATION);
                }
                else
                {
                        Statut_Form->Statut_Label->Caption = "Processing canceled";
                }
                Main_Form->Enabled = true ;
                Statut_Form->Close();
        }

}
//---------------------------------------------------------------------------

