/*******************************************************************************
*       Fichier            : Statut_Unit.h                                     *
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

#ifndef Statut_UnitH
#define Statut_UnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TStatut_Form : public TForm
{
__published:	// IDE-managed Components
        TPanel *Statut_Panel;
        TLabel *Statut_Label;
        TSpeedButton *Cancel_SpeedButton;
        void __fastcall Cancel_SpeedButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TStatut_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TStatut_Form *Statut_Form;
//---------------------------------------------------------------------------
#endif
