#pragma warning(disable : 4996)

/*	Copyright (C) 2019 by Rizky Khapidsyah */

#include <stdio.h>
#include <conio.h>
#include <Windows.h>

long BACA_FILE(char NAMA_FILE[80])
{
	FILE *Data; 
	int Lihat;
	long Panggil;

	Data = fopen(NAMA_FILE, "a+");
	Lihat = ftell(Data);

	fseek(Data, 0L, SEEK_END);
	Panggil = ftell(Data);

	fseek(Data, Lihat, SEEK_SET);
	fclose(Data);

	return Panggil;
}

void main()
{
	FILE *Data_Pesan;
	long Buka_Pesan = 0;
	char Nama_Pesan[100];

	Buka_Pesan = BACA_FILE("Pesan.rpf");
	Data_Pesan = fopen("Pesan.rpf", "a+");

	if (Buka_Pesan == 0)
	{
		printf("Tidak ada File pesan (*.rpf)!");
	}
	else
	{
		while (fgets(Nama_Pesan, sizeof Nama_Pesan, Data_Pesan) != NULL)
		{
			printf(Nama_Pesan, stdout);
			MessageBox(NULL, Nama_Pesan, "Testing", MB_ICONEXCLAMATION | MB_OK);
		}
		fclose(Data_Pesan);
	}
	_getch();
}