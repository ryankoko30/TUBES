#include "sub_main.h"

void master(List_child &LC,List_parent &LP,List_relasi &LR){
    string jawab;
    while (jawab != "c"){
            system("cls");
            cout<<"masuk sebagai"<<endl;
            cout<<"a.admin"<<endl;
            cout<<"b.pelanggan"<<endl;
            cout<<"c.keluar"<<endl;
            cin>>jawab;
            if ( jawab == "a"){
                admin(LC,LP,LR);
            }
            else if ( jawab == "b"){
                pelanggan(LC,LP,LR);
            }
            else if ( jawab == "c"){
                exit(0);
            }
    }

}

void admin(List_child &LC,List_parent &LP,List_relasi &LR){
    int pil;

    while(pil != 5){
    system("cls");
    cout<<"1.tambah restoran"<<endl;
    cout<<"2.tambah menu "<<endl;
    cout<<"3.hapus restoran"<<endl;
    cout<<"4.hapus menu"<<endl;
    cout<<"5.keluar "<<endl; //kembali ke menu utama
    cout<<"6.lihat restoran"<<endl;
    cout<<"7.lihat menu"<<endl;
    cout<<"pilih : "<<endl;
    cin.ignore();
    cin>>pil;
    if (pil == 1){
        a_tambahR(LC);
        system("pause");
        admin(LC,LP,LR);
    }
    else if (pil == 2){
        a_tambahM(LC,LP,LR);
        system("pause");
         admin(LC,LP,LR);
    }
    else if (pil == 3){
        a_hapusR(LC,LP,LR);
        system("pause");
         admin(LC,LP,LR);
    }
    else if (pil == 4){
        a_hapusM(LC,LP,LR);
        system("pause");
         admin(LC,LP,LR);
    }
    else if (pil ==  5){
        master(LC,LP,LR);
        system("pause");
         admin(LC,LP,LR);
    }
    else if (pil == 6){
        lihat_resto(LC);
        system("pause");
         admin(LC,LP,LR);

    }
    else if (pil == 7){
        lihat_MhargaResto(LC,LP,LR);
        system("pause");
         admin(LC,LP,LR);
    }
    else if (pil == 8 ){
        printInfo(LP);
        system("pause");
         admin(LC,LP,LR);
    }
    }
}

void pelanggan(List_child &LC,List_parent LP,List_relasi &LR){

    system("cls");
    int pilP = 0;
    while(pilP != 4){
    cout<<"1.daftar menu"<<endl;
    cout<<"2.pesan"<<endl;
    cout<<"3.cari menu"<<endl;
    cout<<"4.keluar"<<endl;//ke menu utama
    cin>>pilP;

    if (pilP == 1){
        daftar_menu(LP);
        system("pause");
        pelanggan(LC,LP,LR);
    }
    else if (pilP == 2){
        p_pesan(LC,LP,LR);
        system("pause");
        pelanggan(LC,LP,LR);
    }
    else if (pilP == 3){
        p_cariM(LP,LC,LR);
        system("pause");
        pelanggan(LC,LP,LR);
    }
    }
}
void a_tambahM(List_child LC, List_parent &LP, List_relasi &LR){
    cout<<" tambah makanan "<<endl;
    infotype_parent x;
    address_child R;
    address_parent M;
    address_parent cariM;
    address_relasi Rel;
    infotype_child y;
    cout<<"masukan nama restoran    :";
    cin>>y.nama_resto;
    cout<<"\n";
    R = findElmC(LC,y);
    if (R==NULL){
        cout<<"restoran belum ada";
        cout<<"\n";
        system("pause");
    }
    else{
        cout<<"masukan nama makanan  :";
        cin>>x.nama_makanan;
        cout<<"\n";
        cariM = findElmP(LP,x);
        cout << "done \n";
        if (cariM == NULL){
            M = alokasi(x);
            insertLast(LP,M);
            infotype_relasi hargaR;
            cout<<"masukan harga    :";
            cin>>hargaR.harga;
            cout<<"\n";
            hargaR.jumlah_pesanan=0;
            Rel = alokasi(M,R,hargaR);
            insertLast(LR,Rel);
        }
        else{
            infotype_relasi hargaR;
            cout<<"masukan harga    :";
            cin>>hargaR.harga;
            cout<<"\n";
            hargaR.jumlah_pesanan=0;
            Rel = alokasi(M,R,hargaR);
            insertLast(LR,Rel);
        }
       // system("pause");
    }

    }
void a_tambahR(List_child &LC){
    cout<<" tambah restoran "<<endl;
    infotype_child info_restoran;
    cout<<"Masukan Nama Restoran    : ";
    cin>>info_restoran.nama_resto;
    cout<<"\n";
    address_child x = alokasi(info_restoran);
    info(x).jumlah_pendapatan = 0;
    insertLast(LC,x);
    }

void lihat_resto(List_child &LC){
    cout<<" LIHAT RESTORAN \n";

    cout<<"done";
    if(first(LC) == NULL){
        cout<<" restoran tidak ada kosong \n";
    }else{
        printInfo(LC);
    }
}
void lihat_MhargaResto(List_child &LC,List_parent &LP,List_relasi &LR){
    cout<<" LIHAT MENU DAN HARGA DI RESTORAN \n";
    if(first(LC) == NULL){
        cout<<" restoran tidak ada / kosong \n";
    }else{
        infotype_child x;
        address_child C;
        cout<<"cari restoran            : ";
        cin>>x.nama_resto;
        C = findElmC(LC,x);
      if ( C != NULL){
        if ( first(LP)== NULL){
            cout<<info(C).nama_resto;
            if(C == NULL){
                cout<<" restoran tidak ada kosong \n";
                }else{
                cout<<" menu di restoran "<<info(C).nama_resto<<" tidak ada \n";
            }
        }
        else{
            cout<<" Wellcome to Restoran "<<info(C).nama_resto<<endl;
            cout<<"==========MENU==========\n";
            printInfo(LC);
            cout<<" JUMLAH PENDAPATAN : "<<info(C).jumlah_pendapatan;
        }
       }
    else{
        cout<<" RESTORAN KOSONG ";
    }
    }
}

void a_hapusM(List_child &LC,List_parent &LP,List_relasi &LR){
   cout<<" Hapus Menu "<<endl;
    infotype_child x;
    infotype_parent y;
    infotype_relasi z;
    address_parent P;
    address_child C;
    address_relasi R;
    cout<<"cari restoran            : ";
    cin>>x.nama_resto;
    C = findElmC(LC,x);
    if(C == NULL){
        cout<<" restoran tidak ada / kosong \n";
    }else{
        //cout<<info(C).nama_resto;
        cout<<"cari menu : ";
        cin>>y.nama_makanan;
        P = findElmP(LP,y);
        if (P == NULL){
            cout<<" menu tidak ada / kosong \n";
        }else{
        /*R=first(LR);
            while ( next(R)!= first(LR)){
                if ( child(R) == C ){
                    deleteRelasi(LR,R);
                    cout<<"done";
                }
                R=next(R);
            }
            */
            deleteParent(LP,P);
            cout<<"DONE";
        }
    }
}
void a_hapusR(List_child &LC,List_parent LP,List_relasi &LR){
    cout<<" Hapus Restoran "<<endl;
    infotype_child x;
    infotype_parent y;
    address_child C;
    cout<<"cari restoran            : ";
    cin>>x.nama_resto;
    C = findElmC(LC,x);
    if(C == NULL){
        cout<<" restoran tidak ada kosong \n";
    }else{
        //cout<<info(C).nama_resto;
        deleteChild(LC,C);
        /*address_parent P = first(LP);
        address_relasi R = first(LR);
        while(P!=NULL)
            if(child(R) == C){
                deleteRelasi(LR,R);
                deleteChild(LC,C);
                cout<<"Berhasil";
            }
            P = next(P);
        }*/
    }


    //system("pause");


    /*do{
        if(child(Rel)==R){
            found=true;
            Q=Rel;
        }
        Rel=next(Rel);
    }while(Rel!=first(LR));
    if(found==true){
        deleteRelasi(LR,Q);
    }*/
    /*while (next(Rel) != first(LR)){
        if (child(Rel) == R){
            address_relasi z ;sa
            z = Rel;
            deleteRelasi(LR,z);
        }
    }*/
}
void p_cariM(List_parent LP,List_child LC,List_relasi LR){
    cout<<" car menu "<<endl;
    infotype_parent x;
    address_parent z;
    string opsi;
    cout<<" masukan menu yang di cari   :";
    cin>>x.nama_makanan;
    cout<<"\n";
    z = findElmP(LP,x);
    if (z != NULL){
        cout<<info(z).nama_makanan;
        do{
            cout<<"apakah ingin pesan ? [Y/N]";
            cin>>opsi;
            cout<<"\n";
        }
        while ((opsi == "Y") || (opsi == "N"));

        if (opsi == "Y"){
            p_pesan(LC,LP,LR);
        }
        else{
            pelanggan(LC,LP,LR);
        }
    } else{
        cout<<"makanan belum ada ";
    }
}
void p_pesan(List_child &LC,List_parent LP,List_relasi &LR){
    cout<<" PESANAN "<<endl;
    address_parent x;
    address_relasi y;
    address_child z;
    infotype_child a;
    infotype_parent cari;
    string P_resto;
    int jum;
    cout<<"mau pesan apa ?";
    cin>>cari.nama_makanan;
    cout<<"\n";
    x = findElmP(LP,cari);
    if (x == NULL){
        cout<<"makanan tidak tersedia"<<endl;
    }
    else{
        y = first(LR);
        while (next(y) != first(LR));{
            if (parent(y) = x){
                cout<<info(child(y)).nama_resto<<" dengan harga     : Rp."<<info(y).harga<<endl;
            }
            y = next(y);
        }
        cout<<"mau pesan di mana?";
        cin>>P_resto;
        cout<<"\n";
        cout<<"mau pesan berapa?";
        cin>>jum;
        cout<<"\n";
        a.nama_resto = P_resto;
        z = findElmC(LC,a);
        y = findElmR(LR,x,z);
        info(y).jumlah_pesanan = info(y).jumlah_pesanan + jum;
        info(z).jumlah_pendapatan = info(z).jumlah_pendapatan + (jum * info(y).harga);

    }
    }
void daftar_menu(List_parent LP){
    cout<<" daftar Menu "<<endl;
    printInfo(LP);
    }



