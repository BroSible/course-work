//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
extern bool isDarkTheme = false; // Изначально используется светлая тема
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Label1->BringToFront();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Form2->Show();
	Form1->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ExitButtonClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToggleThemeClickClick(TObject *Sender)
{
	isDarkTheme = !isDarkTheme; // Инвертировать значение переменной темы
	if (isDarkTheme)
	{
		Form1->Color = clBlack;
		Form1->Label1->Font->Color = clWhite;

		Form2->Color = clBlack;
		Form2->LoginLabel->Font->Color = clWhite;
		Form2->PasswordLabel->Font->Color = clWhite;
        Form2->Label1->Font->Color = clWhite;

		Form3->Color = clBlack;
		Form3->FiltPriceLabel->Font->Color = clWhite;
		Form3->SearchLabelBD->Font->Color = clWhite;
		Form3->Label1->Font->Color = clWhite;
		Form3->Label2->Font->Color = clWhite;
	}
	else
	{
		Form1->Color = clWhite;
		Form1->Label1->Font->Color = clBlack;

		Form2->Color = clWhite;
		Form2->LoginLabel->Font->Color = clBlack;
		Form2->PasswordLabel->Font->Color = clBlack;
		Form2->Label1->Font->Color = clBlack;

		Form3->Color = clWhite;
		Form3->FiltPriceLabel->Font->Color = clBlack;
		Form3->SearchLabelBD->Font->Color = clBlack;
		Form3->Label1->Font->Color = clBlack;
		Form3->Label2->Font->Color = clBlack;
	}

}
//---------------------------------------------------------------------------


void __fastcall TForm1::ChangeTextButtonClick(TObject *Sender)
{
	if(FontDialog1->Execute())
	{
		Form1->Button1->Font->Assign(FontDialog1->Font);
		Form1->ExitButton->Font->Assign(FontDialog1->Font);
		Form1->ChangeTextButton->Font->Assign(FontDialog1->Font);
		Form1->ToggleThemeButton->Font->Assign(FontDialog1->Font);


		Form2->LoginEdit->Font->Assign(FontDialog1->Font);
		Form2->LoginLabel->Font->Assign(FontDialog1->Font);
		Form2->PasswordEdit->Font->Assign(FontDialog1->Font);
		Form2->PasswordLabel->Font->Assign(FontDialog1->Font);

		Form3->DBGrid1->Font->Assign(FontDialog1->Font);
		Form3->FiltPriceLabel->Font->Assign(FontDialog1->Font);
		Form3->SearchLabelBD->Font->Assign(FontDialog1->Font);
		Form3->Label1->Font->Assign(FontDialog1->Font);
		Form3->Label2->Font->Assign(FontDialog1->Font);
		Form3->Button1->Font->Assign(FontDialog1->Font);
		Form3->Button2->Font->Assign(FontDialog1->Font);
		Form3->Button3->Font->Assign(FontDialog1->Font);
	}

}
//---------------------------------------------------------------------------

