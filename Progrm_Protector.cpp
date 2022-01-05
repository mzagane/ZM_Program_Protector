//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Main_Unit.cpp", Main_Form);
USEFORM("Statut_Unit.cpp", Statut_Form);
USEFORM("About_Unit.cpp", About_Form);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TMain_Form), &Main_Form);
                 Application->CreateForm(__classid(TStatut_Form), &Statut_Form);
                 Application->CreateForm(__classid(TAbout_Form), &About_Form);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
