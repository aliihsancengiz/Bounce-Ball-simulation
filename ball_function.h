#ifndef ball_funtion
#define ball_funtion
#define G 9.82
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define abs(x) (x>=0 ? x:-x)
struct real_t{
	float time;
	float xpos;
	float ypos;	
	float velocity;
	float p_energy;
	float k_energy;
	float mass;
	char direction;
};
void constructor(struct real_t *c,float t,float x,float y,float v,float m,char sign){
	c->time=t;
	c->xpos=x;
	c->ypos=y;
	c->velocity=v;
	c->mass=m;
	c->p_energy=m*G*(c->ypos);
	c->k_energy=0.5*m*(c->velocity)*(c->velocity);
	c->direction=sign;
	}
void setpos(struct real_t *target,float x,float y){
	target->xpos=x;
	target->ypos=y;
}
void disppos(struct real_t *t,float i){
	printf("\n---------------------------------------------------\n");
	printf("          %.3f .second                                  \n",i);
	printf("-         X position of ball is :%.4f                \n",t->xpos);
	printf("-         Y position of ball is %.4f                 \n",t->ypos);
	printf("-         Velocity of ball is %.4f                   \n",t->velocity);
	printf("-         Potential energy of ball is %.4f           \n",t->p_energy);
	printf("-         Kinetic energy of ball  is  %.4f           \n",t->k_energy);
	printf("-         Direction of ball is %c                    \n",t->direction);
	printf("-----------------------------------------------------\n");
}
void interface(){
	printf("\nSimulation is started .....\n\n");
}
void delay(float s){
    float ms = 1000*s;
    clock_t start_time = clock();
    while (clock() < start_time + ms)
        ;
}
float vcalculator(float *c,float t){
	float v=(*c)+t*G;
	return v;	
}
float pcalculator(float t,const float temp3){
	float pos=temp3-(0.5*t*t*G);
	return pos;
}
float kcalculator(struct real_t *k){
	float temp;
	temp=(0.5)*(k->mass)*(k->velocity);
	return temp;	
}
float * linspace(const float i1,const float i2,int n){
	float inc=(abs((i1-i2)))/(n-1);
	float *p=NULL;
	p=(float*)malloc(sizeof(float)*n);
	int i=0;
		for(;i<n;i++){
			p[i]=i1+i*inc;
			
		}
	return p;
	
}
float ucalculator(struct real_t *u){
	return ((u->mass)*G*(u->ypos));
	
}
#endif
