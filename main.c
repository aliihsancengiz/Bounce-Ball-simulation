#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "listdata.h"
#include "ball_function.h"
/*
	Name: Bouncer ball simulation
	Copyright: NO COPRÝGHT
	Author: Ali ihsan cengiz
	Date: 25.03.18 22:26
	Description: -
*/

int main(int argc, char *argv[]) {
	
	struct real_t init;  /* initialize a ball object */
	node *databasell=NULL;
	float x_pos,y_pos,b_veloctiy,b_mass;	
	int i,j;
	float timebender,temp;
	float *timer;
	int found=0;
	interface();
	constructor(&init,0.0,0.0,100.0,0,0.2,'-');
	temp=100;
	float intv=0;
	for(i=0;i<=10;i++){	
	timebender=(float)i;
	timer=(float*)linspace(timebender,(timebender+1),11);	

		for(j=0;j<10;j++){	
		init.velocity=vcalculator(&intv,timer[j]); 
		init.ypos=pcalculator(timer[j],temp);
		init.xpos=0;
		init.mass=0.2;
		init.k_energy=kcalculator(&init);
		init.p_energy=ucalculator(&init);
		init.time=timer[j];
		if(init.ypos<0){
		found=1;
		break;	
		}	
		databasell=add(databasell,&init);	
		disppos(&init,timer[j]);
		}
		
		
		if(found==1){
		printf("\n\nball is collapsed...\n\n");
		disppos(&init,timer[j]);
		break;	
		}	
	}
	
	FILE *p;
	p=fopen("database.dat","wb");
	node *templ=databasell;
	
	do {
		fprintf(p,"%.10f %.10f %.10f %.10f \n",templ->btime,templ->vball,templ->kball,templ->pball);
		templ=templ->link;
		
	} while(templ->link!=NULL);
	free(templ);
	templ=NULL;
	free(timer);
	timer=NULL;
	system("PAUSE");
	return 0;
}
