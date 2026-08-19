#include<stdio.h>
#include<conio.h>
	struct student{
		int rollNo;
		char name [50];
		float marks[5];
		float total;
		float average;
		char grade;
	};
	char calculateGrade(float avg) {
		if(avg>=90) return 'A';		
		else if(avg>=75) return 'B';
		else if(avg>=60) return 'C';
				else if(avg>=40) return 'D';
		else if(avg<40) return 'F';
	}
	
	int main(){
	struct student s[100];
	int i,j,n,m;
	printf("Enter the no. of students : ");
	scanf("%d",&n);
	printf("Enter the no. of the subjects : ");
	scanf("%d",&m);
	for (i=0;i<n;i++){
		printf("\nEnter details for students %d\n",i+1);
		printf("Roll Number :  ");
		scanf("%d",&s[i].rollNo);
		printf("Student name: ");
		scanf("%s", s[i].name);
		
		s[i].total=0;
		for(j=0;j<m;j++){
		printf("Enter  marks of subject %d:",j+1);
		scanf("%f",&s[i].marks[j]);
		s[i].total +=s[i].marks[j];
		}
		
		s[i].average=s[i].total/m;
		s[i].grade=calculateGrade(s[i].average);
		}
			printf("\n-------------------------------------------------------------------------------------------------------------------------\n");
	printf("RollNo\tName\tTotal\tAverage\tGrade\n");
	printf("\n-------------------------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<n;i++){
		printf("%d\t%s\t%.2f\t%.2f\t%c\n",s[i].rollNo, s[i].name, s[i].total,s[i].average,s[i].grade);
			printf("\n-------------------------------------------------------------------------------------------------------------------------\n");
	getch();
	}
	

	
	
	
}
