//Source code :
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int i , k;
char tem1[1000] , tem2[1000] , var[100] , d[] = {"%lf"};
void generate(char t[]);
void trigon(char t[] , char ch);
void hyper(char t[] , char ch);
void inverse(char t[] , char ch);
void logar(char t[]);
void power(char t[]);
void exponent(char t[]);
void variable(char ex[] , char a[]);
int search( char c, char a[]);
void print(char fin[]);
int main() {
	char ex[1000] , ch;
	printf("Sir, please enter the expression without space\nuse '^' for power and input in valid arithmetic manner\n");
	printf("TRIGONOMETRIC FUNCTIONS :\nS -> sin\nC -> cos\nT -> tan\n");
	printf("INVERSE TRIGONMETRIC FUNCTIONS :\nSi -> arcsin\nCi -> arccos\nTi -> arctan\n");
	printf("HYPERBOLIC FUNCTIONS :\nSh -> sinh\nCh -> cosh\nTh -> tanh\n");
	printf("EXPONENTIAL FUNCTIONS :\nL -> log\nE -> raised to natural exponent\n");
	scanf("%[^\n]" , ex);
	printf(" Sir, you have entered the following expression.\nPlease check if it is correct else press \"ctrl+z\"\n");
	puts(ex);
	getchar();
	variable(ex , var);
	generate(ex);
	printf("Sir, here is your required program :\n\n\n\n");
	print(ex);
	return 1;
}
void variable(char ex[] , char a[]) {
	char c[2];
	int i1;
	for(i1 = 0; ex[i1] != '\0'; i1++) {
		if(ex[i1] >= 'a' && ex[i1] <= 'z') {
			if(search(ex[i1] , a)) {
				c[0] = ex[i1];
				c[1] = '\0';
				strcat(a , c);
			}
		}
	}
	return ;
}
int search(char c , char a[]) {
	for(i = 0; a[i] != '\0'; i++) {
		if(c == a[i] || c == 'h' || c == 'i') {
			return 0;
		}
	}
	return 1;
}
void generate(char t[]) {
	int x , m , n , a;
	char tem[100] , tem1[100] , tfin[1000];
	x = 0;
	while(t[x] != '\0') {
		if((t[x] == 'C' && t[x+1] == 'h') || (t[x] == 'S' && t[x+1] == 'h') || (t[x] == 'T' && t[x+1] == 'h')) {
			hyper(t , t[x]);
		}
		if((t[x] == 'C' && t[x+1] == 'i') || (t[x] == 'S' && t[x+1] == 'i') || (t[x] == 'T' && t[x+1] == 'i')) {
			inverse(t , t[x]);
		}
		else if((t[x] == 'C' && t[x+1] != 'h') || (t[x] == 'S' && t[x+1] != 'h') || (t[x] == 'T' && t[x+1] != 'h')) {
			trigon(t , t[x]);
		}
		else if(t[x] == 'L') {
			logar(t);
		}
		else if(t[x] == 'E') {
			exponent(t);
		}
		else if(t[x] == '^') {
			for(m = x; !(t[m] == '+' || t[m] == '-' || t[m] == '*' || t[m] == '/'); m--){
			}
			m++;
			a = m;
			n = 0;
			while(1) {
				tem[n] = t[m];
				m++;
				n++;
				if((t[m] == '+' || t[m] == '-' || t[m] == '*' || t[m] == '/') ||t[m] == '\0') {
					break;
				}
			}
			tem[n] = '\0';
			power(tem);
			n = 0;
			for(i = 0; i < a; i++ , n++) {
				tem1[n] = t[i];
			}
			tem1[n] = '\0';
			strcpy(tfin , tem1);
			strcat(tfin , tem);
			n = 0;
			if(t[m]  != '\0') {
				for(i = m; t[i] != '\0'; i++ , n++) {
					tem1[n] = t[i];
				}
				tem1[n] = '\0';
				strcat(tfin , tem1);
			}
			strcpy(t , tfin);
		}
		x++;
	}return ;
	
}
void power(char t[]) {
	i = 0;
	k = 0;
	strcpy(tem1 , "pow(");
	while(t[i] != '^') {
		tem2[k] = t[i];
		i++;
		k++;
	}
	tem2[k] = '\0';
	strcat(tem1 , tem2);
	strcat(tem1 , ",");
	k = 0;
	i++;
	while(t[i] != '\0') {
		tem2[k] = t[i];
		i++;
		k++;
	}
	tem2[k] = '\0';
	strcat(tem1 , tem2);
	strcat(tem1 , ")");
	strcpy(t , tem1);
}
void exponent(char t[]) {
	k = 0;
	i = 0;
	while(t[i] != 'E') {
		tem2[k] = t[i];
		i++;
		k++;
	}	
	tem2[k] = '\0';
	strcpy(tem1 , tem2);
	strcat (tem1 , "exp");
	k = 0;
	i++;
	while(t[i] != '\0') {
		tem2[k] = t[i]; 
		k++;
		i++;
	}
	tem2[k] = '\0';
	strcat(tem1 , tem2);
	strcpy(t , tem1);
	return ;
}
void logar(char t[]) {
	k = 0;
	i = 0;
	while(t[i] != 'L') {
		tem2[k] = t[i];
		i++;
		k++;
	}	
	tem2[k] = '\0';
	strcpy(tem1 , tem2);
	strcat (tem1 , "log");
	k = 0;
	i++;
	while(t[i] != '\0') {
		tem2[k] = t[i]; 
		k++;
		i++;
	}
	tem2[k] = '\0';
	strcat(tem1 , tem2);
	strcpy(t , tem1);
	return ;
}
void trigon(char t[] , char ch) {
	if(ch == 'C') {
		k = 0;
		i = 0;
		while(!(t[i] == 'C' && t[i+1] != 'h')) {
			tem2[k] = t[i];
			i++;
			k++;
		}
		tem2[k] = '\0';
		strcpy(tem1 , tem2);
		strcat (tem1 , "cos");
		k = 0;
		i++;
		while(t[i] != '\0') {
			tem2[k] = t[i]; 
			k++;
			i++;
		}
		tem2[k] = '\0';
		strcat(tem1 , tem2);
	}	
	else if(ch == 'S') {
		k = 0;
		i = 0;
		while(!(t[i] == 'S' && t[i+1] != 'h')) {
			tem2[k] = t[i];
			i++;
			k++;
		}
		tem2[k] = '\0';
		strcpy(tem1 , tem2);
		strcat (tem1 , "sin");
		k = 0;
		i++;
		while(t[i] != '\0') {
			tem2[k] = t[i]; 
			k++;
			i++;
		}
		tem2[k] = '\0';
		strcat(tem1 , tem2);
	}
	else if(ch == 'T') {
		k = 0;
		i = 0;
		while(!(t[i] == 'T' && t[i+1] != 'h')) {	
			tem2[k] = t[i];
			i++;
			k++;
		}
		tem2[k] = '\0';
		strcpy(tem1 , tem2);
		strcat (tem1 , "tan");
		k = 0;
		i++;
		while(t[i] != '\0') {
			tem2[k] = t[i]; 
			k++;
			i++;
		}
		tem2[k] = '\0';
		strcat(tem1 , tem2);
	}
	strcpy(t , tem1);
	return ;
}
void hyper(char t[] , char ch) {	
	if(ch == 'S') {
		k = 0;
		i = 0;
		while(!(t[i] == 'S' && t[i+1] == 'h')) {
			tem2[k] = t[i];
			i++;
			k++;
		}
		tem2[k] ='\0';
		strcpy(tem1 , tem2);
		strcat (tem1 , "sinh");	
		k = 0;
		i++;
		i++;
		while(t[i] != '\0') {
			tem2[k] = t[i]; 
			k++;
			i++;
		}
		tem2[k] = '\0';
		strcat(tem1 , tem2);
	}
	else if(ch == 'C') {
		k = 0;
		i = 0;
		while(!(t[i] == 'C' && t[i+1] == 'h')) {
			tem2[k] = t[i];
			i++;
			k++;
		}
		tem2[k] = '\0';
		strcpy(tem1 , tem2);
		strcat (tem1, "cosh");
		k = 0;
		i++;
		i++;
		while(t[i] != '\0') {
			tem2[k] = t[i]; 
			k++;
			i++;
		}
		tem2[k] = '\0';
		strcat(tem1 , tem2);
	}
	else if(ch == 'T') {
		k = 0;
		i = 0;
		while(!(t[i] == 'T' && t[i+1] == 'h')) {
			tem2[k] = t[i];
			i++;
			k++;
		}
		tem2[k] = '\0';
		strcpy(tem1 , tem2);
		strcat (tem1 , "tanh");
		k = 0;
		i++;
		i++;
		while(t[i] != '\0') {
			tem2[k] = t[i]; 
			k++;
			i++;
		}	
		tem2[k] = '\0';
		strcat(tem1 , tem2);
	}
	strcpy(t , tem1);
	return ;
}
void inverse(char t[] , char ch) {	
	if(ch == 'S') {
		k = 0;
		i = 0;
		while(!(t[i] == 'S' && t[i+1] == 'i')) {
			tem2[k] = t[i];
			i++;
			k++;
		}
		tem2[k] ='\0';
		strcpy(tem1 , tem2);
		strcat (tem1 , "asin");	
		k = 0;
		i++;
		i++;
		while(t[i] != '\0') {
			tem2[k] = t[i]; 
			k++;
			i++;
		}
		tem2[k] = '\0';
		strcat(tem1 , tem2);
	}
	else if(ch == 'C') {
		k = 0;
		i = 0;
		while(!(t[i] == 'C' && t[i+1] == 'i')) {
			tem2[k] = t[i];
			i++;
			k++;
		}
		tem2[k] = '\0';
		strcpy(tem1 , tem2);
		strcat (tem1, "acos");
		k = 0;
		i++;
		i++;
		while(t[i] != '\0') {
			tem2[k] = t[i]; 
			k++;
			i++;
		}
		tem2[k] = '\0';
		strcat(tem1 , tem2);
	}
	else if(ch == 'T') {
		k = 0;
		i = 0;
		while(!(t[i] == 'T' && t[i+1] == 'i')) {
			tem2[k] = t[i];
			i++;
			k++;
		}
		tem2[k] = '\0';
		strcpy(tem1 , tem2);
		strcat (tem1 , "atan");
		k = 0;
		i++;
		i++;
		while(t[i] != '\0') {
			tem2[k] = t[i]; 
			k++;
			i++;
		}	
		tem2[k] = '\0';
		strcat(tem1 , tem2);
	}
	strcpy(t , tem1);
	return ;
}
void print(char fin[]) {
	printf("#include<stdio.h>\n#include<math.h>\n");
	printf("main() {\n");
	printf("	double");
	printf(" %c" , var[0]);
	for(i = 1; var[i] != '\0'; i++) {
		printf(" , %c" , var[i]);
	}
	printf(" , sol;\n");
	for(i = 0; var[i] != '\0'; i++) {
		printf("	printf(\"Enter the value for %c\");\n" , var[i]);
		printf("	scanf(\"%s\" , &%c);\n" , d , var[i]);
	}
	printf("	sol = %s;\n" , fin);
	printf("	printf(\"solution is %s\" , sol);\n}\n" , d);	
}
