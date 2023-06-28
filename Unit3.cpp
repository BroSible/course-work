//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include <Vcl.DBGrids.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;

//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
	for(int i=0;i<DBGrid1->Columns->Count;i++)//настройка ширины колонок
	{
		DBGrid1->Columns->Items[i]->Width=150;
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm3::N1Click(TObject *Sender)
{
	if(InputSearchEdit->Text!="")                     //sql запрос для посика по значению из edit
	{
		AnsiString a=InputSearchEdit->Text;
		ADOQuery1->Active=0;
		ADOQuery1->SQL->Text=
		"SELECT *FROM Бассейн WHERE Название_Услуги = :name";
		ADOQuery1->Parameters->ParamByName("name")->Value = a;
		ADOQuery1->Active=1;
	}
	for(int i=0;i<DBGrid1->Columns->Count;i++)//настройка ширины колонок
	{
		DBGrid1->Columns->Items[i]->Width=150;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N2Click(TObject *Sender)
{
	ADOQuery1->Active=0;                         //sql запрос для сброса фильтров
	ADOQuery1->SQL->Text=
	"select * from Бассейн";
	ADOQuery1->Active=1;

    for(int i=0;i<DBGrid1->Columns->Count;i++)//настройка ширины колонок
	{
		DBGrid1->Columns->Items[i]->Width=150;
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Button1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------



void __fastcall TForm3::N4Click(TObject *Sender)
{
  	ADOQuery1->Active=0;                       //sql запрос для фильтрации по алфавиту
	ADOQuery1->SQL->Text=
	"select * from Бассейн ORDER BY Название_Услуги";
	ADOQuery1->Active=1;
	for(int i=0;i<DBGrid1->Columns->Count;i++)//настройка ширины колонок
	{
		DBGrid1->Columns->Items[i]->Width=150;

	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N5Click(TObject *Sender)
{
	ADOQuery1->Active=0;
	ADOQuery1->SQL->Text = "SELECT * FROM Бассейн ORDER BY Стоимость_1_занятия ASC";
	ADOQuery1->Active=1;

	for(int i=0;i<DBGrid1->Columns->Count;i++)//настройка ширины колонок
	{
		DBGrid1->Columns->Items[i]->Width=150;

	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N6Click(TObject *Sender)
{
	ADOQuery1->Active=0;
	ADOQuery1->SQL->Text = "SELECT * FROM Бассейн ORDER BY Стоимость_1_занятия DESC";
	ADOQuery1->Active=1;

	for(int i=0;i<DBGrid1->Columns->Count;i++)//настройка ширины колонок
	{
		DBGrid1->Columns->Items[i]->Width=150;

	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N7Click(TObject *Sender)
{
    if(Edit1->Text=="")
	{
		ShowMessage("Введите значение в поле для фильтрации!");
	}
	else
	{
		ADOQuery1->Active=0;
		ADOQuery1->SQL->Text = "SELECT * FROM Бассейн WHERE Стоимость_1_занятия <= :FilterValue";
		ADOQuery1->Parameters->ParamByName("FilterValue")->Value = Edit1->Text;
		ADOQuery1->Active=1;
		for(int i=0;i<DBGrid1->Columns->Count;i++)//настройка ширины колонок
		{
		DBGrid1->Columns->Items[i]->Width=150;

		}
    }

}
//---------------------------------------------------------------------------

void __fastcall TForm3::N8Click(TObject *Sender)
{
	if(Edit1->Text=="")
	{
		ShowMessage("Введите значение в поле для фильтрации!");
	}
	else
	{
		ADOQuery1->Active=0;
		ADOQuery1->SQL->Text = "SELECT * FROM Бассейн WHERE Стоимость_1_занятия >= :FilterValue";
		ADOQuery1->Parameters->ParamByName("FilterValue")->Value = Edit1->Text;
		ADOQuery1->Active=1;
		for(int i=0;i<DBGrid1->Columns->Count;i++)//настройка ширины колонок
		{
		DBGrid1->Columns->Items[i]->Width=150;

		}
	}


}
//---------------------------------------------------------------------------

void __fastcall TForm3::N9Click(TObject *Sender)
{
	Form3->Close();
	Form1->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
	// создаем новую запись
	TDataSet *ds = DataSource1->DataSet;
	ds->Append();

	// открываем диалоговое окно для ввода данных
	TFieldDefs* fieldDefs = ds->FieldDefs;
	for (int i = 0; i < fieldDefs->Count; i++)
	{
		TFieldDef* fieldDef = fieldDefs->Items[i];
		String fieldName = fieldDef->Name;
		String fieldValue;
		if (InputQuery("Введите значение", fieldName, fieldValue))
		{
			// сохраняем значение поля
			ds->FieldByName(fieldName)->AsString = fieldValue;
		}
		else
		{
			// отменяем добавление записи
			ds->Cancel();
			return;
		}
	}

	// сохраняем изменения в БД
	ds->Post();

	// освобождаем память

}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button3Click(TObject *Sender)
{
	if(Edit2->Text!="")
{
	TLocateOptions Options;
	if (ADOQuery1->Locate("Название_Услуги",Edit2->Text,Options))
	{
		ADOQuery1->Delete();
		Edit2->Text="";
	}
	else
	{
		ShowMessage("Нет значения для удаления");
	}
}
else
{
	ShowMessage("Заполните поле для удаления") ;
}
}
//---------------------------------------------------------------------------


void __fastcall TForm3::N10Click(TObject *Sender)
{
	if(Edit3->Text=="")
	{
		ShowMessage("Введите значение в поле для фильтрации!");
	}
	else
	{
		ADOQuery1->Active=0;
		ADOQuery1->SQL->Text = "SELECT * FROM Бассейн WHERE Продолжительность_сеанса >= :FilterValue";
		ADOQuery1->Parameters->ParamByName("FilterValue")->Value = Edit3->Text;
		ADOQuery1->Active=1;

		for(int i=0;i<DBGrid1->Columns->Count;i++)//настройка ширины колонок
		{
		DBGrid1->Columns->Items[i]->Width=150;

		}
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm3::N11Click(TObject *Sender)
{
   if(Edit3->Text=="")
	{
		ShowMessage("Введите значение в поле для фильтрации!");
	}
	else
	{
		ADOQuery1->Active=0;
		ADOQuery1->SQL->Text = "SELECT * FROM Бассейн WHERE Продолжительность_сеанса <= :FilterValue";
		ADOQuery1->Parameters->ParamByName("FilterValue")->Value = Edit3->Text;
		ADOQuery1->Active=1;

		for(int i=0;i<DBGrid1->Columns->Count;i++)//настройка ширины колонок
		{
		DBGrid1->Columns->Items[i]->Width=150;

		}
	}
}
//---------------------------------------------------------------------------


