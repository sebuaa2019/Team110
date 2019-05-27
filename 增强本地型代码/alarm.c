#include <stdio.h>
#include "sys_setting.h"

void react(int type,int loc){
	while(1){
	switch(type){
		case 0:
		    if(loc==0){
                SetCall(call_phone,3,0);
                printf("检测到厨房烟雾浓度超标\n");
		    }
		    else if(loc==1){
                SetCall(call_phone,3,1);
                printf("检测到客厅烟雾浓度超标\n");
		    }
			break;
		case 1:
		    if(loc==0){
                SetCall(call_phone,0,0);
                printf("未及时输入密码，判为厨房恶意入侵\n");
		    }
		    else if(loc==1){
                SetCall(call_phone,0,1);
                printf("未及时输入密码，判为客厅恶意入侵\n");
		    }
			break;
		case 2:
		    if(loc==0){
                SetCall(call_phone,2,0);
                printf("厨房恶意入侵\n");
		    }
		    else if(loc==1){
                SetCall(call_phone,2,1);
                printf("未客厅恶意入侵\n");
		    }
			break;
        case 3:
		    if(loc==0){
                SetCall(call_phone,1,0);
                printf("厨房水浸\n");
		    }
		    else if(loc==1){
                SetCall(call_phone,1,1);
                printf("客厅水浸\n");
		    }
			break;
        case 4:
		    if(loc==0){
                SetCall(call_phone,4,0);
                printf("厨房温度过高\n");
		    }
		    else if(loc==1){
                SetCall(call_phone,4,1);
                printf("客厅温度过高\n");
		    }
			break;
	}
	taskDelay(10);
	}
}

void judge_offence(int switch_judge, int loc){
	if(switch_judge == 1){
        if(loc==0){
            react(1,0);
        }
        else{
            react(1,1);
        }
	}
}



