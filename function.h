void load_img();
void first();
void move();
void clash();
void draw();
void initialize();
void make_rotate(double x, double y, double z, double rx, double ry, double rz, double& xx, double& yy, double& zz);
void  make_3d_2d(double x, double y, double z, double& xx, double& yy);
int check_surface(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3);
double shade(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3);
double med3(double x, double y, double z);
void quicksort(double a[], int b[], int left, int right);