#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

int main(){
FILE *p,*q;
	int npontos,nfuncoes;
	char *funcoes;
    char *aux;
	float **pontos;
	int j,h,i,n,k,mno=0,t=0,o=1,r=1;
    int z,v;
    int result;
    float M, E;
	float **a, **m,**l,**pega;
	float *b, *y, *s,*x;
	float *aux1, *aux2 , *aux3 , *aux4;
	float **Ge;
	float soma=0,soma2=0;
	char aa[1],bb[1],cc[1],dd[1],ee[1],ff[1],gg[1],hh[1],ii[1],jj[1];
	char auxiliar[1];
	
	aa[0]='a';
	aa[1]='\0';

    bb[0]='b';
	bb[1]='\0';

    cc[0]='c';
	cc[1]='\0';

    dd[0]='d';
	dd[1]='\0';

    ee[0]='e';
	ee[1]='\0';

    ff[0]='f';
	ff[1]='\0';

    gg[0]='g';
	gg[1]='\0';

    hh[0]='h';
	hh[1]='\0';

    ii[0]='i';
	ii[1]='\0';

    jj[0]='j';
	jj[1]='\0';
		
	p=fopen("entrada.txt","r");
	q=fopen("saida.txt","w");

	fscanf(p,"%d",&n);
	for(i=0;i<n;i++){
		fscanf(p,"%d",&npontos);	
		aux1=(float*)malloc(npontos*sizeof(float));
		aux2=(float*)malloc(npontos*sizeof(float));
		
		for(z=0;z<npontos;z++){
			fscanf(p,"%f, %f; ",&aux1[z],&aux2[z]);
		}	
		fscanf(p,"%d",&nfuncoes);	
		h=(2*nfuncoes);
		funcoes=(char*)malloc(nfuncoes*sizeof(char));
		aux=(char*)malloc(h*sizeof(char));	
		
		for(z=0;z<=h;z++){
			aux[z]=fgetc(p);	
		}
		b=(float*)malloc(nfuncoes*sizeof(float));
		y=(float*)malloc(nfuncoes*sizeof(float));
		s=(float*)malloc(nfuncoes*sizeof(float));
		x=(float*)malloc(nfuncoes*sizeof(float));
		a=(float**)malloc(nfuncoes*sizeof(float*));

		for(z=0;z<nfuncoes;z++){
			a[z]=(float*)malloc(nfuncoes*sizeof(float));
		}
		pega=(float**)malloc(nfuncoes*sizeof(float*));

		for(z=0;z<nfuncoes;z++){
			pega[z]=(float*)malloc(nfuncoes*sizeof(float));
		}
		m=(float**)malloc(nfuncoes*sizeof(float*));

		for(z=0;z<nfuncoes;z++){
			m[z]=(float*)malloc(nfuncoes*sizeof(float));
		}
		l=(float**)malloc(nfuncoes*sizeof(float*));

		for(z=0;z<nfuncoes;z++){
			l[z]=(float*)malloc(nfuncoes*sizeof(float));
		}
		Ge=(float**)malloc(npontos*sizeof(float*));

		for(z=0;z<npontos;z++){
			Ge[z]=(float*)malloc(nfuncoes*sizeof(float));
		}

		for(j=0;j<nfuncoes;j++){
			for(z=0;z<nfuncoes;z++){
				a[j][z] = 0; 
				m[j][z] = 0;
				l[j][z] = 0;
		   }
			b[j] = 0;
			y[j] = 0;
			s[j] = 0;
			x[j] = 0;
		}
	
		for(z=0;z<h;z++){
			auxiliar[0]=aux[z];
			auxiliar[1]='\0';
			if(auxiliar[0]=='+'){
				t=t;
			}
			else{
				if(auxiliar[0]=='a'){
					for(j=0;j<npontos;j++){
	        			Ge[j][t]=sin(aux1[j]);
		       		}
					t++;	
				}
				if(auxiliar[0]=='b'){
					for(j=0;j<npontos;j++){
	        			Ge[j][t]=cos(aux1[j]);
		       		}
					t++;
				}
				if(auxiliar[0]=='c'){
	        		for(j=0;j<npontos;j++){
	        			Ge[j][t]=log(aux1[j]);
		       		}
					t++;
				}
				if(auxiliar[0]=='d'){
	        		for(j=0;j<npontos;j++){
	        			Ge[j][t]=pow((2.7182),aux1[j]);
		       		}
					t++;
				}
				if(auxiliar[0]=='e'){
	        		for(j=0;j<npontos;j++){
	        			Ge[j][t]=pow(aux1[j],5);
		       		}
					t++;
				}
				if(auxiliar[0]=='f'){
	        		for(j=0;j<npontos;j++){
	        			Ge[j][t]=pow(aux1[j],4);
		       		}
					t++;
				}
				if(auxiliar[0]=='g'){
	        		for(j=0;j<npontos;j++){
	        			Ge[j][t]=pow(aux1[j],3);
		       		}
					t++;
				}
				if(auxiliar[0]=='h'){
	        		for(j=0;j<npontos;j++){
	        			Ge[j][t]=pow(aux1[j],2);
		       		}
					t++;
				}
				if(auxiliar[0]=='i'){
	        		for(j=0;j<npontos;j++){
	        			Ge[j][t]=aux1[j];
		       		}
					t++;
				}
				if(auxiliar[0]=='j'){
					for(j=0;j<npontos;j++){
	        			Ge[j][t]=1;
		       		}
					t++;
				}
			}
		}
		t=0;
		for(z=0;z<nfuncoes;z++){
			for(j=0;j<nfuncoes;j++){
				for(v=0;v<npontos;v++){
					soma=soma+(Ge[v][j]*Ge[v][z]);
				}
				a[j][z]=soma;
				soma=0;
			}
			soma=0;
		}
		soma=0;
		for(z=0;z<nfuncoes;z++){
			for(v=0;v<npontos;v++){
				soma2=soma2+(Ge[v][z]*aux2[v]);
			}
			b[z]=soma2;
			soma2=0;
		}
		soma2=0;
		for(j=0;j<(nfuncoes)-1;j++){
			for(z=j+1;z<nfuncoes;z++){
				M = a[z][j] / a[j][j];
				a[z][j] = 0;
				m[z][j] = M;
				for(k=j+1;k<nfuncoes;k++){
					a[z][k] = a[z][k] - (M * a[j][k]);
				}
			}
		}
		for(z=0;z<nfuncoes;z++){     
			for(j=0;j<nfuncoes;j++){
				if(z==j){
					l[z][j] = 1;
				}
				else{
					if(z>j){
						l[z][j] = m[z][j];
					}
				}
			}
		}
		y[0] = b[0];
		for(k=1;k<nfuncoes;k++){
			y[k] = b[k];
			for(j=k;j>=0;j--){
				s[k] = s[k] + l[k][j-1] * y[j-1];
				y[k] = b[k] - s[k];
			}
		}
		for(z=(nfuncoes-1);z>=0;z--){
			E=0;
			if(z!=(nfuncoes-1)){
				for(k=(nfuncoes-1);k>=z+1;k--){
					E = E + (a[z][k] * x[k]);
				}
			}
			x[z] = (y[z] - E) / a[z][z];
		}
		fprintf(q,"no caso %d: \n",i+1);
		for(z=0;z<nfuncoes;z++){
			fprintf(q,"%.5f, ",x[z]);
		}	
		fprintf(q,"\n\n");
		
		free(Ge);
		free(aux);
		free(aux1);
		free(a);
		free(m);
		free(l);
		free(b);
		free(y);
		free(s);
		free(x);
		free(aux2);
		free(aux3);
		free(aux4);
		free(pega);
	}
	
	fclose(p);
	fclose(q);
	
	return 0;	
	
}


