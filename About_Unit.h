/*******************************************************************************
*       Fichier            : Abou_Unit.h                                       *
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

#ifndef About_UnitH
#define About_UnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TAbout_Form : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TImage *Image1;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Web_Site_Label;
        TLabel *Label7;
        TSpeedButton *Ok_SpeedButton;
        void __fastcall Web_Site_LabelClick(TObject *Sender);
        void __fastcall Label7Click(TObject *Sender);
        void __fastcall Ok_SpeedButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TAbout_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAbout_Form *About_Form;
//---------------------------------------------------------------------------
#endif
