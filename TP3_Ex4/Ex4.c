#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main() {
    int i = 0, j = 0, a = 0, b = 0, c = 0, d = 0;
    unsigned int MyAddress_w = 192, MyAddress_x = 168, MyAddress_y = 129, MyAddress_z = 10,
        MyAddress = 0,
        IPv4MaskLength = 24,
        IPV4 = 0,
        w = 0,
        x = 0,
        y = 0,
        z = 0,
        w1 = 0,
        x1 = 0,
        y1 = 0,
        a1 = 0,
        b1 = 0,
        c1 = 0,
        Adresse_reseau = 0,
        NotMask_a = 0,
        NotMask_b = 0,
        NotMask_c = 0,
        NotMask_d = 255,
        NotMask = 0,
        Adresse_Broadcast = 0;

    /*masque réseau*/
    for (i = 0; i <= IPv4MaskLength; i++) {
        IPV4 += 1;
        IPV4 = (IPV4 << 1);



    }
    for (j = IPv4MaskLength + 1; j < 32; j++) {
        IPV4 = (IPV4 << 1);
    }

    MyAddress = (MyAddress_w << 24) + (MyAddress_x << 16) + (MyAddress_y << 8) + (MyAddress_z); //met l'adresse IP sur 24 bits mais peut être codé sur plus
    Adresse_reseau = MyAddress & IPV4;
    w = Adresse_reseau >> 24;
    w1 = w << 24;  //
    x = Adresse_reseau - (w1) >> 16;
    x1 = x << 16;
    y = Adresse_reseau - (w1 + x1) >> 8;
    y1 = y << 8;
    z = Adresse_reseau - (w1 + x1 + y1);

    NotMask = (NotMask_a << 24) + (NotMask_b << 16) + (NotMask_c << 8) + (NotMask_d);
    Adresse_Broadcast = Adresse_reseau | NotMask;
    a = Adresse_Broadcast >> 24;
    a1 = w << 24;
    b = Adresse_Broadcast - (a1) >> 16;
    b1 = x << 16;
    c = Adresse_Broadcast - (a1 + b1) >> 8;
    c1 = y << 8;
    d = Adresse_Broadcast - (a1 + b1 + c1);

    printf("adresse IPV4 : %d.%d.%d.%d/%d", MyAddress_w, MyAddress_x, MyAddress_y, MyAddress_z, IPv4MaskLength);
    printf("\nadresse du reseau : %u.%u.%u.%u/%d", w, x, y, z, IPv4MaskLength);
    printf("\nadresse broadcast : %u.%u.%u.%u", a, b, c, d);

}