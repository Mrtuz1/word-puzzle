#include <stdio.h>
#define n 100
int main(){
	char tahmin[n];
	char truetahmin[n][n];
	char D[6] = {'u','e','l','m','i','k'};
	char kelimeler[n][6]  ={"ilmek","imlek","melik","kule","ilke","ekim","mil","kem","kum","kel","kil","ilk","ile","lim","el","il"};
	int puan=0,i=0,j=0,counter1=1,counter2=0,counter3=0,counter4=0,counter5=0,a=0;
	int uzunluk,Dlength,signword;
	for (Dlength=0;D[Dlength]!='\0';Dlength++){}  //D dizisinin uzunluðu
	printf("kullanabileceginiz harfler:");
	for(i=0;i<Dlength;i++){
		printf("%c ",D[i]);
	}
	for(signword=0;kelimeler[signword][0]!='\0';signword++){}
	printf("\n");
	scanf("%s",&tahmin);
	while(tahmin[0]!='0'){
		if(counter5!=signword){
		uzunluk=0;
		i=0;
		while(tahmin[i]!='\0'){
			i++;
			uzunluk+=1;
		}
					if(uzunluk!=1){
		for(i=0;i<uzunluk;i++){  //bu for bloðunun amacý harfler doðru kullanýlmýþ mý ona bakmak.
			if (counter1==1){
				counter1=0;  //counter1 1 ise tahminimin i. harfi d dizisinde vardýr tahmin dizisindeki sonraki harfe bakmaya yarar.
			}
			else{
				counter2+=1;  //counter2 0'dan farklý ise puan kýracak.0 olmalý
			}
			for(j=0;j<Dlength;j++){
				if(D[j]==tahmin[i]){
					counter1=1;
				}
			}
		}
		if(counter2!=0){
			printf("yanlis harf kullanimi yaptiniz!\n");
		}//bir harf birden fazla kullanýlmýþsa counter2 artacak hem yanlýþ harf kullanýlmamýþ hem bir harf bir defa kullanýlmýþsa counter2 0 olacak sonraki karþýlaþtýrmalarda kullanacaðým.
		for(i=0;i<uzunluk-1;i++){
			for(j=i+1;j<uzunluk;j++){
				if(tahmin[i]==tahmin[j]){
					counter2+=1;
				}
			}
		}//counter2 0dan farklý ise hatalýdýr aklýnda bulunsun.
		for(i=0;i<signword;i++){
			counter1=0;
			for(j=0;j<uzunluk;j++){
				if(tahmin[j]==kelimeler[i][j]){
					counter1+=1;
					if(counter1==uzunluk){
						counter3=1;  //counter3 1 ise anlamlý kelimelerdendir
					}
				}				
			}
		}
	    for(i=0;i<n;i++){
			counter1=0;
			for(j=0;j<uzunluk+1;j++){
				if(tahmin[j]==truetahmin[i][j]){
					counter1+=1;
					if(counter1==uzunluk+1){
						counter4=1;  //counter4 0 ise eski tahminlerde yoktur bu da istediðimiz yani counter4 0 olmalý
					}
				}				
			}
		}
		if(counter2==0){
			if(counter3==1){
				if(counter4==0){
					counter5+=1;
					puan+=uzunluk;
					printf("%d puan kazandiniz :)\n\n",uzunluk);
					for(i=0;i<uzunluk+1;i++){
				truetahmin[a][i]=tahmin[i];
			}
			a++;
				}
				else{
					printf("bu kelimeyi daha once tahmin ettiniz\n");
					printf("%d puan kaybettiniz :(\n\n",uzunluk);
					puan-=uzunluk;
				}
			}
			else{
				printf("anlamli kelime girilmeli!\n");
				printf("%d puan kaybettiniz :(\n\n",uzunluk);
				puan-=uzunluk;
			}
		}
		else{
			puan-=uzunluk;
			printf("%d puan kaybettiniz :(\n\n",uzunluk);
		}
}
else {
	printf("tek harf girmeyiniz!\n");
}
if(counter5!=signword){
printf("tahmininizi giriniz:");
    scanf("%s",tahmin); }
	counter1=1;
	counter2=0;
	counter3=0;
	counter4=0;
}
else{
	tahmin[0]='0';
}
	}
	printf("oyunu basariyla tamamladiniz tebrikler!\nIste puaniniz:%d\n",puan);
	printf("oyundan çikmak için herhangi bir tusa basiniz ");
	scanf("%d",tahmin);
return 0;
}
