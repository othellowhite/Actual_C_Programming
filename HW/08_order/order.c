
/*
	+ Order
 
	R에 대해 대응하는 순서 S를 찾아 한줄에 출력
	n은 1 ~ 100
	불가능할 경우에 IMPASSIBLE
	
	Boys : 최성현 최윤승 박민욱
*/


//헤더 선언부
#include<stdio.h>
#include<stdlib.h>

#define MAX_N 100 //최대 n값 정의

void f_Order_function(int no_datas, int r_datas[]);
void upper_line(int n, int arry[]);

void main()
{
	FILE * in_file; //file open을 위한 포인터 변수 선언
	int no_cases;
	int no_datas;
	int i,j;

	in_file = fopen("input.txt","r"); //리소스파일인 input.txt에서 파일을 읽을 준비 

	fscanf(in_file,"%d",&no_cases); //i개의 테스트 데이터
	
	//i번 돌아갈 예정
	for(i = 0; i < no_cases; i++)
	{
		///*****************************************************************************
		///여기서부터 알고리즘 시작*****************************************************
		int r_datas[MAX_N];

		fscanf(in_file,"%d",&no_datas); //data의 갯수를 읽는다.

		//data를 r_data에 저장한다.
		for(j = 0; j < no_datas; j++)
		{
			fscanf(in_file,"%d",&r_datas[j]);
		}
		
		//F_Order 계산 함수에 넣어준다.
		f_Order_function(no_datas, r_datas);
	}
}

//F_Order 계산 함수부분.
void f_Order_function(int no_datas, int r_datas[])
{

	//변수 선언부분
	int i,j;
	int temp;
	int output_data[MAX_N]; //출력할 output data를 저장할 변수
	int temp_datas[MAX_N]; // S값을 찾을 때 오름차순으로 정렬될 임시 숫자가 들어갈 변수

	/***********************************인자 전달이 제대로 되어있나 확인
	for(i = 0; i < no_datas; i++)
	{
		printf("%d ",r_datas[i]);
	}
	printf("\n");
	***********************************인자 전달이 제대로 되어있나 확인*/


	/*
	//i는 1씩 증가할 때 j는 i로부터 1씩 0이 될때 까지 감소한다.
	for(i =0; i < no_datas; i ++)
	{
		output_data[i] = i+1; //data값에 1부터 no_datas값까지 순차적으로 체워준다.

		//그 뒤에 그 전까지 조합에 타당한지 판단한다.
		//이때 바꿔야 될 숫자가 있으면 바꿔주는데
		//여기서 error일 경우에 detec값이 1로 변하게된다.
		for(j = i; j > 0; j--)
		{
			//r값의 인덱스인 i보다 r값에 저장된 수가 클 경우에 error
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
	
	//out put data에 순차적으로 입력
	for(i = 0; i < no_datas; i++)
	{
		output_data[i] = i+1;
	}
	

	//r값의 인덱스인 i보다 r값에 저장된 수가 클 경우에 error
	for(i = 0; i < no_datas; i++)
	{
		if(i < r_datas[i]) 
		{
			printf("IMPOSSIBLE\n");
			return;
		}
	}

	//s값을 구해서 outputdata에 넣어준다.
	for(i = no_datas-1; i >=0; i--)
	{
		upper_line(i, output_data);
		temp = output_data[i];
		output_data[i] = output_data[r_datas[i]];
		output_data[r_datas[i]] = temp;
	}
	///////////////////////////////////////////////////////////////////////////////////
	//output data를 출력해준다.
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