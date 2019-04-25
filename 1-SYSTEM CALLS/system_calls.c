#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	int fd_dup,fd,op;
	int return_value;
	char name[100], *read_data, *write_data;
	do
	{
		printf("\nThe calls: \n");
		printf("1. Creat\n");
		printf("2. Open\n");
		printf("3. Close\n");
		printf("4. Read\n");
		printf("5. Write\n");
		printf("6. Lseek\n");
		printf("7. Duplicate\n");
		printf("8. Link\n");
		printf("9. Unlink\n");
		printf("Enter the option: ");
		scanf("%d",&op);
		
		switch(op)
		{
			case 1 ://Creating a File
				printf("Enter the name of the file: ");
				scanf("%s",name);
			   	fd = creat(name, S_IRWXU);
				printf("\n the file is created");
				printf("%d",fd);
				break;

			case 2 ://Opening a File
				printf("Enter the file name to be opened :");
				scanf("%s", name);
				fd = open(name, O_CREAT || O_RDWR);
				printf("%d",fd);
				break;

			case 3: //Closing the file that was opened in case 2
				return_value = close(fd); // return success
				if( return_value == 0)
					printf("\n File successfully closed");
				else if( return_value == -1)
					printf("\n File closure error.");
				break;

			case 4: //Reading from a file
				read_data = (char*)malloc(sizeof(char) * 100);
				printf("Enter the file name to be read :");
				scanf("%s",name);
				fd = open(name,  O_RDONLY);
				return_value = read(fd, read_data, 4); // fd, buf, count
				if( return_value == -1)
					printf("Error in reading");
				else
				{	read_data[return_value] = '\0'; 
					printf("The 4 characters read are: %s",read_data);
				}
				break;

			case 5: //Writing into the file
				write_data = (char*)malloc(100);
				printf("Enter the file to which the data is to be written: ");
				scanf("%s",name);
				fd = creat(name,  S_IRWXU);
				printf("Enter the data to be written: ");		
				scanf("%s",write_data);
				return_value = write(fd, write_data, strlen(write_data));
				if( return_value != -1 )
					printf("Data is written into the file");
				else
					printf("Error in writing data");
				close(fd);
				break;				

			case 6: //Lseek
				return_value = lseek(fd, 2, SEEK_SET); 	
				if(return_value == -1)
					printf("\n Error");
				else
					printf("\n The offset position: %d",return_value);
					//printf("The data at seek position :")
				break;
			case 7: // Creating dup fd
				fd_dup = dup(fd);
				printf("\nFile descriptor duplicated");
				break;
			case 8: //Link
				link("asdfgh","newname");
				break;
			case 10: //Unlink
				unlink("asdfgh");
				break;
				

				
				
		}
	}while(op != 10);
}
