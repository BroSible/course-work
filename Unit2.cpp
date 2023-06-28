//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
bool passwordVisible = false;


//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::NextButtonClick(TObject *Sender)
{
	if((Form2->LoginEdit->Text == "admin" && Form2->PasswordEdit->Text == "1234") || (Form2->LoginEdit->Text == "user" && Form2->PasswordEdit->Text == "1111"))
	{
		if(LoginEdit->Text == "user")
        {
            Form3->DBGrid1->ReadOnly = true;
			Form3->Button2->Visible = false;
			Form3->Label1->Visible = false;
			Form3->Edit2->Visible = false;
			Form3->Button3->Visible = false;
			LoginEdit->Text="";
			PasswordEdit->Text="";
        }
		if(LoginEdit->Text == "admin")
		{
			Form3->DBGrid1->ReadOnly = false;
			Form3->Button2->Visible = true;
			Form3->Label1->Visible = true;
			Form3->Edit2->Visible = true;
			Form3->Button3->Visible = true;
			LoginEdit->Text="";
            PasswordEdit->Text="";
		}
		Form2->Close();
		Form3->Show();
	}
 else if(Form2->LoginEdit->Text == "admin" || Form2->LoginEdit->Text == "user")
 {
  	ShowMessage("Неверный пароль");
 }
 else
 {
	 ShowMessage("Нет такого пользователя");
 }


}
//---------------------------------------------------------------------------


void __fastcall TForm2::BackButtonClick(TObject *Sender)
{
	Form2->Close();
    Form1->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::CheckBox1Click(TObject *Sender)
{

	if (CheckBox1->Checked)
	{
		PasswordEdit->PasswordChar = 0x2605;
	} else
	{
		PasswordEdit->PasswordChar = 0;
	}



}
//---------------------------------------------------------------------------

