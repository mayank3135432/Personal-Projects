#include<stdio.h>
#include<math.h>
struct quat{
    double real;
    double ith;
    double jth;
    double kth;
};
typedef struct quat quat;

quat dot(quat q1,quat q2){
    quat c;
    c.real=q1.real*q2.real-q1.ith*q2.ith-q1.jth*q2.jth-q1.kth*q2.kth;
    c.ith=q1.real*q2.ith+q2.real*q1.ith+q1.jth*q2.kth-q2.jth*q1.kth;
    c.jth=q1.real*q2.jth-q1.ith*q2.kth+q2.real*q1.jth+q2.ith*q1.kth;
    c.kth=q1.real*q2.kth+q1.ith*q2.jth-q2.ith*q1.jth+q2.real*q1.kth;
    return(c);
}
quat dot(quat q,double x){
    quat p={q.real*x,q.ith*x,q.jth*x,q.kth*x};
    return(p);
}
quat dot(double x,quat q){
    quat p={q.real*x,q.ith*x,q.jth*x,q.kth*x};
    return(p);
}
quat add(quat q1,quat q2){
    quat c;
    c.real=q1.real+q2.real;
    c.ith=q1.ith+q2.ith;
    c.jth=q1.jth+q2.jth;
    c.kth=q1.kth+q2.kth;
    return(c);
}
double mag(quat q){
    return(sqrt(q.real*q.real+q.ith*q.ith+q.jth*q.jth+q.kth*q.kth));
}
void print(quat q){
    printf("\n(%lf,%lf,%lf,%lf)\n",q.real,q.ith,q.jth,q.kth);
}
int main(){
    quat q1={2,4,1,6};
    quat q2={2,-4,-1,-6};
    quat c=dot(q1,q2);
    print(c);
    printf("%lf || %lf\n",mag(q1),mag(c));

    return 0;
}