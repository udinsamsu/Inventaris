#include<stdio.h>
#include<string.h>

#define MAX_BARANG 10
#define MAX_PANJANG_NAMA 50

char nama[20];
char nabar[MAX_BARANG][MAX_PANJANG_NAMA];
char probar[MAX_BARANG][MAX_PANJANG_NAMA];
int tabar[MAX_BARANG],kobar[MAX_BARANG],habar[MAX_BARANG];
int jumlahBarang = 0;


void judul(){
	printf("Masukkan nama anda : ");
	scanf("%[^\n]s", nama);
	getchar();
	printf("===== Selamat datang %s di program inventaris barang ===== \n", nama);
}

void inputBarang(){
	if(jumlahBarang < MAX_BARANG){	
		printf("Masukkan nama barang : ");
		scanf("%[^\n]s", nabar[jumlahBarang]);
		getchar();
		printf("Masukkan nama produsen barang : ");
		scanf("%[^\n]s", probar[jumlahBarang]);
		getchar();
		printf("Masukkan tahun produksi barang : ");
		scanf("%d", &tabar[jumlahBarang]);
		printf("Masukkan kode barang : ");
		scanf("%d", &kobar[jumlahBarang]);
		printf("Masukkan harga barang : ");
		scanf("%d", &habar[jumlahBarang]);
		jumlahBarang++;
		printf("Barang berhasil ditambahkan");
	}else{
		printf("Jumlah barang sudah tercapai : ");
	}
}

void menampilkan(){
	if(jumlahBarang != 0){
		for(int i = 0; i < jumlahBarang; i++){
			printf("Barang ke-%d\n", i+1);
			printf("Nama Barang : %s\n", nabar[i]);
			printf("Nama Produsen barang : %s\n", probar[i]);
			printf("Tahun Produksi barang : %d\n", tabar[i]);
			printf("Kode barang : %d\n", kobar[i]);
			printf("Harga barang : Rp %d\n\n\n", habar[i]);
		}
	}else{
		printf("Barang belum ditambahkan");
	}
}

void cariBarang(){
	int cabar;
	int ditemukan=0;
	
	printf("Masukkan kode barang yang ingin dicari : ");
	scanf("%d", &cabar);
	
	for(int i = 0; i < jumlahBarang; i++){
		if(cabar==kobar[i]){
			ditemukan = 1;
			printf("Barang ditemukan\n");
			printf("Nama Barang : %s\n", nabar[i]);
			printf("Nama Produsen barang : %s\n", probar[i]);
			printf("Tahun Produksi barang : %d\n", tabar[i]);
			printf("Kode barang : %d\n", kobar[i]);
			printf("Harga barang : Rp %d\n", habar[i]);
			break;
		}
	}
	
	if(!ditemukan){
		printf("Barang tidak ditemukan di dalam database");
	}
}

void hapusBarang(){
	int hasbar;
	int ditemukan=0;
	
	printf("Masukkan kode barang yang ingin dihapus : ");
	scanf("%d", &hasbar);
	
	for(int i = 0; i < jumlahBarang; i++){
		if(hasbar==kobar[i]){
			ditemukan = 1;
			for(int j = i; j < jumlahBarang - 1; j++){
				strcpy(nabar[j], nabar[j+1]);
				strcpy(probar[j], probar[j+1]);
				tabar[j], tabar[j+1];
				habar[j], habar[j+1];
				kobar[j], kobar[j+1];
			}
			jumlahBarang--;
			
			printf("Barang dengan kode %d telah dihapus", hasbar);
			break;
		}
	}
	
	if(!ditemukan){
		printf("Barang tidak ditemukan di dalam database");
	}
}

void jualBarang(){
	int kodeJual;
	int hargaJual;
	int ditemukan=0;
	
	printf("Masukkan kode barang yang ingin dijual : ");
	scanf("%d", &kodeJual);
	
	for(int i = 0; i < jumlahBarang; i++){
		if(kodeJual==kobar[i]){
			ditemukan = 1;
			printf("Nama barang : %s\n", nabar[i]);
			printf("Harga barang : %d\n", habar[i]);
			printf("Masukkan harga jual barang : ");
			scanf("%d", &hargaJual);
			
			int labaRugi = hargaJual-habar[i];
			
			printf("Laba atau Rugi penjualan : %d", labaRugi);
			jumlahBarang--;
		}
	}
	
	if(!ditemukan){
		printf("Barang tidak ditemukan di dalam database");
	}
}

int main(){
	int pilihan;
	judul(nama);
	do {
		printf("\nMenu\n");
		printf("1. Input data barang \n");
		printf("2. Menampilkan data barang \n");
		printf("3. Mencari barang\n");
		printf("4. Menghapus barang\n");
		printf("5. Jual barang\n");
		printf("6. Keluar\n");
		printf("Pilih menu(1/2/3/4/5/6) : ");
		scanf("%d", &pilihan);
		printf("\n");
		
		switch(pilihan){
			case 1 :
				getchar();
				inputBarang();
				break;
			case 2 :
				menampilkan();
				break;
			case 3 :
				cariBarang();
				break;
			case 4 :
				hapusBarang();
				break;
			case 5 :
				jualBarang();
				break;
			case 6 :
				printf("Terima kasih, silakan datang lagi\n");
				break;
			default:
				printf("Pilihan tidak valid");
		}
	}while(pilihan!= 6);
	return 0;

}
