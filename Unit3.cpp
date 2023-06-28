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
	for(int i=0;i<DBGrid1->Columns->Count;i++)//��������� ������ �������
	{
		DBGrid1->Columns->Items[i]->Width=150;
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm3::N1Click(TObject *Sender)
{
	if(InputSearchEdit->Text!="")                     //sql ������ ��� ������ �� �������� �� edit
	{
		AnsiString a=InputSearchEdit->Text;
		ADOQuery1->Active=0;
		ADOQuery1->SQL->Text=
		"SELECT *FROM ������� WHERE ��������_������ = :name";
		ADOQuery1->Parameters->ParamByName("name")->Value = a;
		ADOQuery1->Active=1;
	}
	for(int i=0;i<DBGrid1->Columns->Count;i++)//��������� ������ �������
	{
		DBGrid1->Columns->Items[i]->Width=150;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N2Click(TObject *Sender)
{
	ADOQuery1->Active=0;                         //sql ������ ��� ������ ��������
	ADOQuery1->SQL->Text=
	"select * from �������";
	ADOQuery1->Active=1;

    for(int i=0;i<DBGrid1->Columns->Count;i++)//��������� ������ �������
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
  	ADOQuery1->Active=0;                       //sql ������ ��� ���������� �� ��������
	ADOQuery1->SQL->Text=
	"select * from ������� ORDER BY ��������_������";
	ADOQuery1->Active=1;
	for(int i=0;i<DBGrid1->Columns->Count;i++)//��������� ������ �������
	{
		DBGrid1->Columns->Items[i]->Width=150;

	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N5Click(TObject *Sender)
{
	ADOQuery1->Active=0;
	ADOQuery1->SQL->Text = "SELECT * FROM ������� ORDER BY ���������_1_������� ASC";
	ADOQuery1->Active=1;

	for(int i=0;i<DBGrid1->Columns->Count;i++)//��������� ������ �������
	{
		DBGrid1->Columns->Items[i]->Width=150;

	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N6Click(TObject *Sender)
{
	ADOQuery1->Active=0;
	ADOQuery1->SQL->Text = "SELECT * FROM ������� ORDER BY ���������_1_������� DESC";
	ADOQuery1->Active=1;

	for(int i=0;i<DBGrid1->Columns->Count;i++)//��������� ������ �������
	{
		DBGrid1->Columns->Items[i]->Width=150;

	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N7Click(TObject *Sender)
{
    if(Edit1->Text=="")
	{
		ShowMessage("������� �������� � ���� ��� ����������!");
	}
	else
	{
		ADOQuery1->Active=0;
		ADOQuery1->SQL->Text = "SELECT * FROM ������� WHERE ���������_1_������� <= :FilterValue";
		ADOQuery1->Parameters->ParamByName("FilterValue")->Value = Edit1->Text;
		ADOQuery1->Active=1;
		for(int i=0;i<DBGrid1->Columns->Count;i++)//��������� ������ �������
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
		ShowMessage("������� �������� � ���� ��� ����������!");
	}
	else
	{
		ADOQuery1->Active=0;
		ADOQuery1->SQL->Text = "SELECT * FROM ������� WHERE ���������_1_������� >= :FilterValue";
		ADOQuery1->Parameters->ParamByName("FilterValue")->Value = Edit1->Text;
		ADOQuery1->Active=1;
		for(int i=0;i<DBGrid1->Columns->Count;i++)//��������� ������ �������
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
	// ������� ����� ������
	TDataSet *ds = DataSource1->DataSet;
	ds->Append();

	// ��������� ���������� ���� ��� ����� ������
	TFieldDefs* fieldDefs = ds->FieldDefs;
	for (int i = 0; i < fieldDefs->Count; i++)
	{
		TFieldDef* fieldDef = fieldDefs->Items[i];
		String fieldName = fieldDef->Name;
		String fieldValue;
		if (InputQuery("������� ��������", fieldName, fieldValue))
		{
			// ��������� �������� ����
			ds->FieldByName(fieldName)->AsString = fieldValue;
		}
		else
		{
			// �������� ���������� ������
			ds->Cancel();
			return;
		}
	}

	// ��������� ��������� � ��
	ds->Post();

	// ����������� ������

}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button3Click(TObject *Sender)
{
	if(Edit2->Text!="")
{
	TLocateOptions Options;
	if (ADOQuery1->Locate("��������_������",Edit2->Text,Options))
	{
		ADOQuery1->Delete();
		Edit2->Text="";
	}
	else
	{
		ShowMessage("��� �������� ��� ��������");
	}
}
else
{
	ShowMessage("��������� ���� ��� ��������") ;
}
}
//---------------------------------------------------------------------------


void __fastcall TForm3::N10Click(TObject *Sender)
{
	if(Edit3->Text=="")
	{
		ShowMessage("������� �������� � ���� ��� ����������!");
	}
	else
	{
		ADOQuery1->Active=0;
		ADOQuery1->SQL->Text = "SELECT * FROM ������� WHERE �����������������_������ >= :FilterValue";
		ADOQuery1->Parameters->ParamByName("FilterValue")->Value = Edit3->Text;
		ADOQuery1->Active=1;

		for(int i=0;i<DBGrid1->Columns->Count;i++)//��������� ������ �������
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
		ShowMessage("������� �������� � ���� ��� ����������!");
	}
	else
	{
		ADOQuery1->Active=0;
		ADOQuery1->SQL->Text = "SELECT * FROM ������� WHERE �����������������_������ <= :FilterValue";
		ADOQuery1->Parameters->ParamByName("FilterValue")->Value = Edit3->Text;
		ADOQuery1->Active=1;

		for(int i=0;i<DBGrid1->Columns->Count;i++)//��������� ������ �������
		{
		DBGrid1->Columns->Items[i]->Width=150;

		}
	}
}
//---------------------------------------------------------------------------


