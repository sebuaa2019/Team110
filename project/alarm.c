#include <stdio.h>

void react(int type){
	switch(type){
		case 0: printf("检测到烟雾浓度超标\n");
			break;
		case 1: printf("未及时输入密码，判为恶意\n");
			break;
		case 2: printf("恶意入侵\n");
			break;
	}
}

void judge_offence(int switch_judge){
	if(switch_judge == 1) react(1);
}



