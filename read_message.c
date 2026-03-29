#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void)
{

	//variables
	int msg_id2 = 0;
	struct msg{
		int msg_id;
		char usrname[10];
		char msg_body[512];
	};
	


	FILE *out = fopen("message_output.bin", "rb");
	if(!out)
	{
	printf("fopen error\n");
	}

	while(1)
	{
		struct msg message;
		if(fread(&message, sizeof(struct msg), 1, out) == 1)
		{
			if(msg_id2 != message.msg_id){
				printf(">>>%s: %s\n", message.usrname, message.msg_body);
				msg_id2 = message.msg_id;
			}
		} else {
			clearerr(out);
			usleep(2000);
		}

	} fclose(out);
}
