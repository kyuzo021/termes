#include <stdio.h>
#include <string.h>

int main(void)
{
	
	//variables
	char *username = "kyuzo";
	char message_input[512];
	static int counter = 1;

	struct msg{
		int msg_id;
		char usrname[10];
		char msg_body[512];
	};
	


	FILE *out = fopen("message_output.bin", "ab");
	if(!out)
	{
	printf("fopen error.\n");
	}


	while(1)
	{
		
		struct msg message;
		strcpy(message.usrname, username);
		
		message.msg_id = counter;
		counter++;

		printf(">>>%s:", username);

		if(!fgets(message.msg_body, sizeof(message.msg_body), stdin))
		{
			printf("Input error. (1)\n Exitting sessions..\n");
			break;
		}

		message.msg_body[strcspn(message.msg_body, "\n")] = '\0';
	
		if(strcmp(message.msg_body, ".exit") == 0) //ends loop if .exit typed.
		{
			printf("Exitting sessions..\n");	
			break;
		}

		fwrite(&message, sizeof(struct msg), 1, out);
		fflush(out);

	}

	fclose(out);
}
