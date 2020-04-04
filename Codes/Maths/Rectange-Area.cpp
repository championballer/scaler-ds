int area(int xt, int yt, int xb, int yb)
{
    int length = abs(xt-xb);
    int width = abs(yt-yb);
    return length*width;
}

int Solution::solve(int A, int B, int C, int D, int E, int F, int G, int H) {
    
    int xt = min(C,G);
    int yt = min(D,H);
    int xb = max(A,E);
    int yb = max(B,F);
    
    if(xt<xb || yt<yb)return 0;
    return area(xt,yt,xb,yb);
}
