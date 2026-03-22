/*
untuk memudahkan memanggil variabel, dilakukan deklarasi dan inisiasi variabel const int
nomor pin arduino ke nama lampu deklarasikan dengan huruf pertama adalah warna lampu dan huruf ke dua adalah posisi lampunya
contoh: re untuk red east, dan sebagainya
*/

//deklarasi dan inisiasi lampu simpang timur
const int re = 13; const int ye = 12; const int ge = 11;
//deklarasi dan inisiasi lampu simpang utara
const int rn = 10; const int yn = 9; const int gn = 8;
//deklarasi dan inisiasi lampu simpang barat
const int rw = 7; const int yw = 6; const int gw = 5;
//iisiasi lampu simpang selatan
const int rs = 4; const int ys = 3; const int gs = 2;

void setup()
{
  //inisiasi pin pada pinMode semua led adalah sebuah output
  pinMode(rn, OUTPUT); // merah utara
  pinMode(yn, OUTPUT); // kuning utara
  pinMode(gn, OUTPUT); // hijau utara
  
  pinMode(re, OUTPUT); // merah timur
  pinMode(ye, OUTPUT); // kuning timur
  pinMode(ge, OUTPUT); // hijau timur
  
  pinMode(rs, OUTPUT); // merah selatan
  pinMode(ys, OUTPUT); // kuning selatan
  pinMode(gs, OUTPUT); // hijau selatan
  
  pinMode(rw, OUTPUT); // merah barat
  pinMode(yw, OUTPUT); // kuning barat
  pinMode(gw, OUTPUT); // hijau barat
  
  //menginisasikan bahwa semua lampu merah dalam posisi menyala
  for (int i=2; i<=13; i++){
    pinMode(i,OUTPUT);
  }
  digitalWrite(rn,HIGH);
  digitalWrite(re,HIGH);
  digitalWrite(rs,HIGH);
  digitalWrite(rw,HIGH);
  //hold lampu merah sebelum looping setiap pertama kali run
  delay(1000);
}

void simpangOn(int red, int yellow, int green){
  /*
  - untuk mengatur bagaimana jadwal lampu menyala
  - lampu dimulai dari posisi utara dan kembali lagi ke utara secara bergantian sesuai arah jaruh jam
  - lampu merah harus menyala semua saat pertama kali di run
  */
  
  // mematikan lampu merah, menyalakan lampu hijau selama 5 detik
  
  digitalWrite(red,LOW);
  digitalWrite(green, HIGH);
  delay(5000); 
  digitalWrite(green, LOW);

  for (int i = 0; i < 3; i++) {
    digitalWrite(yellow, HIGH);
    delay(333); 
    digitalWrite(yellow, LOW);
    delay(333);
  }
  
  digitalWrite(red, HIGH);
}

void loop(){
  //buat looping trafficnya nyala gantian dari utara->timur->selatan->barat
  simpangOn(rn,yn,gn); // simpang utara
  simpangOn(re,ye,ge);// simpang timur
  simpangOn(rs,ys,gs); // simpang selatan
  simpangOn(rw,yw,gw); // simpang barat
}
