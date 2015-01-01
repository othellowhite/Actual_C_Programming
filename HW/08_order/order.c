
/*
	+ Order
 
	R�� ���� �����ϴ� ���� S�� ã�� ���ٿ� ���
	n�� 1 ~ 100
	�Ұ����� ��쿡 IMPASSIBLE
	
	Boys : �ּ��� ������ �ڹο�
*/


//��� �����
#include<stdio.h>
#include<stdlib.h>

#define MAX_N 100 //�ִ� n�� ����

void f_Order_function(int no_datas, int r_datas[]);
void upper_line(int n, int arry[]);

void main()
{
	FILE * in_file; //file open�� ���� ������ ���� ����
	int no_cases;
	int no_datas;
	int i,j;

	in_file = fopen("input.txt","r"); //���ҽ������� input.txt���� ������ ���� �غ� 

	fscanf(in_file,"%d",&no_cases); //i���� �׽�Ʈ ������
	
	//i�� ���ư� ����
	for(i = 0; i < no_cases; i++)
	{
		///*****************************************************************************
		///���⼭���� �˰��� ����*****************************************************
		int r_datas[MAX_N];

		fscanf(in_file,"%d",&no_datas); //data�� ������ �д´�.

		//data�� r_data�� �����Ѵ�.
		for(j = 0; j < no_datas; j++)
		{
			fscanf(in_file,"%d",&r_datas[j]);
		}
		
		//F_Order ��� �Լ��� �־��ش�.
		f_Order_function(no_datas, r_datas);
	}
}

//F_Order ��� �Լ��κ�.
void f_Order_function(int no_datas, int r_datas[])
{

	//���� ����κ�
	int i,j;
	int temp;
	int output_data[MAX_N]; //����� output data�� ������ ����
	int temp_datas[MAX_N]; // S���� ã�� �� ������������ ���ĵ� �ӽ� ���ڰ� �� ����

	/***********************************���� ������ ����� �Ǿ��ֳ� Ȯ��
	for(i = 0; i < no_datas; i++)
	{
		printf("%d ",r_datas[i]);
	}
	printf("\n");
	***********************************���� ������ ����� �Ǿ��ֳ� Ȯ��*/


	/*
	//i�� 1�� ������ �� j�� i�κ��� 1�� 0�� �ɶ� ���� �����Ѵ�.
	for(i =0; i < no_datas; i ++)
	{
		output_data[i] = i+1; //data���� 1���� no_datas������ ���������� ü���ش�.

		//�� �ڿ� �� ������ ���տ� Ÿ������ �Ǵ��Ѵ�.
		//�̶� �ٲ�� �� ���ڰ� ������ �ٲ��ִµ�
		//���⼭ error�� ��쿡 detec���� 1�� ���ϰԵȴ�.
		for(j = i; j > 0; j--)
		{
			//r���� �ε����� i���� r���� ����� ���� Ŭ ��쿡 error
			if(i < r_datas[i]) 
			{
				printf("IMPOSSIBLE\n");
				return;
			}
			upper_line(j,output_data);


		}
	}
	*/
	/////////////////////////////////////////////////////////////////////////////////////
	
	//out put data�� ���������� �Է�
	for(i = 0; i < no_datas; i++)
	{
		output_data[i] = i+1;
	}
	

	//r���� �ε����� i���� r���� ����� ���� Ŭ ��쿡 error
	for(i = 0; i < no_datas; i++)
	{
		if(i < r_datas[i]) 
		{
			printf("IMPOSSIBLE\n");
			return;
		}
	}

	//s���� ���ؼ� outputdata�� �־��ش�.
	for(i = no_datas-1; i >=0; i--)
	{
		upper_line(i, output_data);
		temp = output_data[i];
		output_data[i] = output_data[r_datas[i]];
		output_data[r_datas[i]] = temp;
	}
	///////////////////////////////////////////////////////////////////////////////////
	//output data�� ������ش�.
	for(i = 0; i < no_datas; i++)
	{
		printf("%d ", output_data[i]);
	}
	printf("\n");
	return;
}

void upper_line(int n, int arry[])
{
	int i, ii;
	int temp;
	 for(i = 0; i < n; i++)
    {
        for(ii = 0; (ii + i) < n; ii++)
        {
            if(arry[ii] > arry[ii + 1])
            {
                temp = arry[ii];
                arry[ii] = arry[ii + 1];
                arry[ii + 1] = temp;
            }
        }
    }
}