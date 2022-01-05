/*******************************************************************************
*       Fichier            : Main_Unit.h                                       *
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

#ifndef Main_UnitH
#define Main_UnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <CheckLst.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TMain_Form : public TForm
{
__published:	// IDE-managed Components
        TPageControl *Main_PageControl;
        TTabSheet *Dir_TabSheet;
        TTabSheet *Extension_TabSheet;
        TGroupBox *GroupBox1;
        TLabel *Dir_Label;
        TSpeedButton *Brows_SpeedButton;
        TEdit *Basic_Dir_Edit;
        TGroupBox *GroupBox2;
        TCheckListBox *Extension_CheckListBox;
        TGroupBox *GroupBox3;
        TSpeedButton *Add_SpeedButton;
        TEdit *New_Extension_Edit;
        TLabel *New_Extension_Label;
        TSpeedButton *Rename_SpeedButton;
        TSpeedButton *Restor_SpeedButton;
        TSpeedButton *Quit_SpeedButton;
        TLabel *About_Label;
        TTabSheet *Options_TabSheet;
        TLabel *String_To_Add_Label;
        TEdit *String_To_Add_Edit;
        TCheckBox *Sub_Dirs_CheckBox;
        TTabSheet *Help_TabSheet;
        TMemo *Memo1;
        TLabel *Label1;
        void __fastcall Brows_SpeedButtonClick(TObject *Sender);
        void __fastcall Add_SpeedButtonClick(TObject *Sender);
        void __fastcall Quit_SpeedButtonClick(TObject *Sender);
        void __fastcall Rename_SpeedButtonClick(TObject *Sender);
        void __fastcall About_LabelClick(TObject *Sender);
        void __fastcall Restor_SpeedButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMain_Form(TComponent* Owner);

        //variables
        AnsiString Basic_Dir;// le repertoire de base
        AnsiString String_To_Add;// une chaine de caractère à ajouter a l'etension
        bool Treatment_Canceled;
        TStringList * Checked_Extension_StrLst;
        //méthodes
        void __fastcall Rename(AnsiString Dir, bool Sub_Dirs);// pour changer les extension des fichiers
        void __fastcall Restor(AnsiString Dir, bool Sub_Dirs);// pour restaurer les extension des fichiers
};
//---------------------------------------------------------------------------
extern PACKAGE TMain_Form *Main_Form;
//---------------------------------------------------------------------------
#endif
