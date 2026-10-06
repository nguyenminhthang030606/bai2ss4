#include <stdio.h>

int main() {
    int n;
    int don_hop_le = 0;
    int don_loi = 0;
    float tong_doanh_thu = 0;
    float don_lon_nhat = 0;

    printf("=== COFFEE_POS - CHOT SO DOANH THU CA ===\n");
    printf("Nhap so luong hoa don: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("\nCa lam viec khong co hoa don.\n");
    } else {
        for (int i = 1; i <= n; i++) {
            float gia_co_so;
            char size;
            int so_topping;
            int member;
            float tien_don;

            printf("\n--- Hoa don %d ---\n", i);

            printf("Nhap gia co so: ");
            scanf("%f", &gia_co_so);

            printf("Nhap size (S/M/L): ");
            scanf(" %c", &size);

            printf("Nhap so luong topping: ");
            scanf("%d", &so_topping);

            printf("Nhap trang thai hoi vien (1-Gold, 0-Thuong): ");
            scanf("%d", &member);

            if (gia_co_so <= 0 ||
                !(size == 'S' || size == 's' ||
                  size == 'M' || size == 'm' ||
                  size == 'L' || size == 'l')) {

                printf("Loi du lieu! Hoa don duoc bo qua.\n");
                don_loi++;
                continue;
            }

            if (so_topping < 0) {
                printf("CANH BAO: Phat hien du lieu bat thuong!\n");
                printf("He thong dung ca lam viec ngay lap tuc.\n");
                break;
            }

            tien_don = gia_co_so;

            if (size == 'M' || size == 'm') {
                tien_don += 6000;
            } else if (size == 'L' || size == 'l') {
                tien_don += 10000;
            }

            tien_don += so_topping * 8000;

            if (member == 1) {
                tien_don = tien_don * 90 / 100;
            }

            don_hop_le++;
            tong_doanh_thu += tien_don;

            if (tien_don > don_lon_nhat) {
                don_lon_nhat = tien_don;
            }

            printf("Thanh tien: %.0f VND\n", tien_don);
        }
    }

    printf("\n====================================\n");
    printf("BAO CAO DOANH THU CA\n");
    printf("Don hop le: %d\n", don_hop_le);
    printf("Don loi/bi bo qua: %d\n", don_loi);
    printf("Tong doanh thu: %.0f VND\n", tong_doanh_thu);
    printf("Don hang lon nhat: %.0f VND\n", don_lon_nhat);
    printf("====================================\n");

    return 0;
}