#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

float funcao (float a0,float a1,float a2,float a3,float a4,float a5,float x){
    float y;
    y=a0*cos(a1*x)+a2*sin(a3*x)+exp(a4*x)+a5;
    return y;
}

float funcaoderiv (float a0,float a1,float a2,float a3,float a4,float a5,float x){
    float y;
    y= (-a1)*a0*sin(a1*x)+a3*a2*cos(a3*x)+a4*exp(a4*x);
    return y;
}

float funcaosecderiv (float a0,float a1,float a2,float a3,float a4,float a5,float x){
    float y;
    y= (-a1)*a1*a0*cos(a1*x)+(-a3)*a3*a2*sin(a3*x)+a4*a4*exp(a4*x);
    return y;
}

float *bissecao (float a0,float a1,float a2,float a3,float a4,float a5,float NMax,float e1,float e2,float a,float b){
	
    float c, x0,x1,d,e,z;
    float *r;
    float i=0;
    z=NMax;
	   
	x0=(b+a)/2;
    
	d=fabs(funcao(a0, a1, a2, a3, a4, a5, x0));
	if(d<=e2){
		r=(float*)malloc(5*sizeof(float));
		
		r[0]=1;
	    r[1]=i;
	    r[2]=x0;
		r[3]=0;
		r[4]=d;		
	}

	
			
	else {
		while(i!=z){
			i++;
			if (funcao(a0, a1, a2, a3, a4, a5, a)*funcao(a0, a1, a2, a3, a4, a5, x0)<0)
            	{b=x0;}
        	if (funcao(a0, a1, a2, a3, a4, a5, a)*funcao(a0, a1, a2, a3, a4, a5, x0)>0)
            	{a=x0;}
        	
        	x1=x0;
        	x0=(b+a)/2;
        	c=x1-x0;
			d=fabs(funcao(a0, a1, a2, a3, a4, a5, x0));
			if(d<=e2){
				if(fabs(c)<=e1){
					break;
				}
			}
		}
		r=(float*)malloc(5*sizeof(float));
		if (i==z)
			r[0]=0;
		else 
			r[0]=1;
		r[1]=i;
		r[2]=x0;
		r[3]=fabs(x1-x0);
		r[4]=d;}
		return r;
    }

float *newton (float a0,float a1,float a2,float a3, float a4, float a5,float NumMax, float e1,float e2,float a,float b) {
	
	float x0,x1,k,pm,m,c,d,z;
	float i=0;
	float *r;
	z=NumMax;
	pm=(a+b)/2;
	k=funcao(a0, a1,a2,a3,a4,a5,pm);
	m=funcaoderiv(a0, a1,a2,a3,a4,a5,pm);
	
	if((fabs(k))<=(e2)){
		
		r=(float*)malloc(5*sizeof(float));
		r[0]=1;
	    r[1]=i;
	    r[2]=pm;
		r[3]=0;
		r[4]=fabs(k);	
	}
	else{
		x0=pm;
		while(i!=z){
			i++;
			k=funcao(a0,a1,a2,a3,a4,a5,x0);
	    	m=funcaoderiv(a0,a1,a2,a3,a4,a5,x0);
	    	x1=x0;
			x0=x0-(k/m);	
			c=x1-x0;
			d=fabs(funcao(a0, a1, a2, a3, a4, a5, x0));
			if(fabs(c)<=e1){
				if(d<=e2){
					break; 
				}
			}
		}
		r=(float*)malloc(5*sizeof(float));	
		if(i==z)
			r[0]=0;
		else
			r[0]=1;
		r[1]=i;
		r[2]=x0;
		r[3]=fabs(x1-x0);
		r[4]=d;
	}
	return r;	
}

float *halley (float a0,float a1,float a2,float a3, float a4, float a5,float NumMax, float e1,float e2,float a,float b){

	float *r;
	float x0,x1,k,pm,m,g,d,c,z;
	float i=0;	
	z=NumMax;
	pm=(a+b)/2;
	k=funcao(a0, a1,a2,a3,a4,a5,pm);
	m=funcaoderiv(a0, a1,a2,a3,a4,a5,pm);
	g=funcaosecderiv(a0, a1,a2,a3,a4,a5,pm);
	
	if((fabs(k))<=(e2)){
		r=(float*)malloc(5*sizeof(float));
		r[0]=1;
	    r[1]=i;
	    r[2]=pm;
		r[3]=0;
		r[4]=fabs(k);
	}
	
	else{	
		x0=pm;
		while(i!=z){
			i++;
			k=funcao(a0, a1,a2,a3,a4,a5,x0);
			m=funcaoderiv(a0, a1,a2,a3,a4,a5,x0);
			g=funcaosecderiv(a0, a1,a2,a3,a4,a5,x0);
			x1=x0;
			x0=x0-(2*k*m)/(2*pow(m,2)-k*g);
			c=x1-x0;
			d=fabs(funcao(a0,a1,a2,a3,a4,a5,x0));
			if(fabs(c)<=e1){
				if(d<=e2){
					break;
				}
			}
		}
		r=(float*)malloc(5*sizeof(float));
		if(i==z)
			r[0]=0;	
		else
			r[0]=1;
		r[1]=i;
		r[2]=x0;
		r[3]=fabs(x1-x0);
		r[4]=d;
	}
	return r;	
}


int main(){
	
	
	FILE *p,*q;
	float A0,A1,A2,A3,A4,A5,NMAX,E1,E2,A,B;
	float *result;
    int i=1,j,f,g=0,h,l,k;
    int c;
	int nlinhas=0,ncaract=0;
	float conv,ite,raiz,er1,er2;
	p=fopen("entrada.txt","r");
	q=fopen("saida.txt","w");
	
	fscanf(p,"%f %f %f %f %f %f %f %f %f %f %f",&A0,&A1,&A2,&A3,&A4,&A5,&NMAX,&E1,&E2,&A,&B);
			
	while((c=fgetc(p))!=EOF){
			
		result=bissecao (A0, A1, A2, A3, A4, A5, NMAX, E1, E2, A, B);
		conv=result[0];
		ite=result[1];
		raiz=result[2];
		er1=result[3];
		er2=result[4];
			
		fprintf(q,"RESULTADO BISSEÇÃO (EQUAÇÃO %d) :\n",i);
		
		if (conv==1)
			fprintf(q,"CONVERGIU, O NÚMERO DE ITERAÇÕES FOI: %.5f, O VALOR ENCONTRADO PARA X FOI: %.5f, |X(i)-X(i-1)|: %.5f, |F(Xi)|: %.5f \n\n", ite, raiz, er1, er2);
		else
			fprintf(q,"NÃO CONVERGIU, PORÉM,  O NÚMERO DE ITERAÇÕES FOI: %.5f, O VALOR ENCONTRADO PARA X FOI: %.5f, |X(i)-X(i-1)|: %.5f, |F(Xi)|: %.5f \n\n",ite, raiz, er1, er2);
			
		result=newton (A0, A1, A2, A3, A4, A5, NMAX, E1, E2, A, B);
		conv=result[0];
		ite=result[1];
		raiz=result[2];
		er1=result[3];
		er2=result[4];
	
		fprintf(q,"RESULTADO NEWTON (EQUAÇÃO %d) :\n",i);
		
		if (conv==1)
			fprintf(q,"CONVERGIU, O NÚMERO DE ITERAÇÕES FOI: %.5f, O VALOR ENCONTRADO PARA X FOI: %.5f, |X(i)-X(i-1)|: %.5f, |F(Xi)|: %.5f \n\n", ite, raiz, er1, er2);
		else
			fprintf(q,"NÃO CONVERGIU, PORÉM,  O NÚMERO DE ITERAÇÕES FOI: %.5f, O VALOR ENCONTRADO PARA X FOI: %.5f, |X(i)-X(i-1)|: %.5f, |F(Xi)|: %.5f \n\n",ite, raiz, er1, er2);
			
		result=halley (A0, A1, A2, A3, A4, A5, NMAX, E1, E2, A, B);
		conv=result[0];
		ite=result[1];
		raiz=result[2];
		er1=result[3];
		er2=result[4];
			
		fprintf(q,"RESULTADO HALLEY (EQUAÇÃO %d) :\n",i);
		
		if (conv==1)
			fprintf(q,"CONVERGIU, O NÚMERO DE ITERAÇÕES FOI: %.5f, O VALOR ENCONTRADO PARA X FOI: %.5f, |X(i)-X(i-1)|: %.5f, |F(Xi)|: %.5f \n\n", ite, raiz, er1, er2);
		else
			fprintf(q,"NÃO CONVERGIU, PORÉM,  O NÚMERO DE ITERAÇÕES FOI: %.5f,  O VALOR ENCONTRADO PARA X FOI: %.5f, |X(i)-X(i-1)|: %.5f, |F(Xi)|: %.5f \n\n",ite, raiz, er1, er2);
		
		fprintf(q,"\n \n \n \n");
		i++;
		fscanf(p,"%f %f %f %f %f %f %f %f %f %f %f",&A0,&A1,&A2,&A3,&A4,&A5,&NMAX,&E1,&E2,&A,&B);
	}
				
	fclose(q);
	fclose(p);
}







