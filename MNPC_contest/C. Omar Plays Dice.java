import java.util.Scanner;
 
public class Main {
    static class Complex {
        double real, imag;
 
        Complex(double real, double imag) {
            this.real = real;
            this.imag = imag;
        }
 
        Complex add(Complex other) {
            return new Complex(this.real + other.real, this.imag + other.imag);
        }
 
        Complex subtract(Complex other) {
            return new Complex(this.real - other.real, this.imag - other.imag);
        }
 
        Complex multiply(Complex other) {
            return new Complex(this.real * other.real - this.imag * other.imag, this.real * other.imag + this.imag * other.real);
        }
 
        Complex divide(double val) {
            return new Complex(this.real / val, this.imag / val);
        }
    }
 
    // Implementation of FFT
    static void fft(Complex[] a, boolean invert) {
        int n = a.length;
        if (n == 1)
            return;
 
        Complex[] a0 = new Complex[n / 2];
        Complex[] a1 = new Complex[n / 2];
        for (int i = 0; 2 * i < n; i++) {
            a0[i] = a[2 * i];
            a1[i] = a[2 * i + 1];
        }
        fft(a0, invert);
        fft(a1, invert);
 
        double ang = 2 * Math.PI / n * (invert ? -1 : 1);
        Complex w = new Complex(1, 0);
        Complex wn = new Complex(Math.cos(ang), Math.sin(ang));
        for (int i = 0; 2 * i < n; i++) {
            a[i] = a0[i].add(w.multiply(a1[i]));
            a[i + n / 2] = a0[i].subtract(w.multiply(a1[i]));
            if (invert) {
                a[i] = a[i].divide(2);
                a[i + n / 2] = a[i + n / 2].divide(2);
            }
            w = w.multiply(wn);
        }
    }
 
    static double[] multiply(double[] a, double[] b) {
        int n = 1;
        while (n < a.length + b.length)
            n <<= 1;
        Complex[] fa = new Complex[n];
        Complex[] fb = new Complex[n];
        for (int i = 0; i < n; i++) {
            fa[i] = new Complex((i < a.length) ? a[i] : 0, 0);
            fb[i] = new Complex((i < b.length) ? b[i] : 0, 0);
        }
 
        fft(fa, false);
        fft(fb, false);
        for (int i = 0; i < n; i++)
            fa[i] = fa[i].multiply(fb[i]);
        fft(fa, true);
 
        double[] result = new double[n];
        for (int i = 0; i < n; i++)
            result[i] = fa[i].real;
        return result;
    }
 
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        double[] a = new double[n + 1];
        double[] b = new double[n + 1];
        for (int i = 1; i <= n; i++)
            a[i] = scanner.nextDouble();
        for (int i = 1; i <= n; i++)
            b[i] = scanner.nextDouble();
 
        int q = scanner.nextInt();
        double[] ans = multiply(a, b);
        for (int i = 0; i < q; i++) {
            int x = scanner.nextInt();
            System.out.printf("%.10f\n", ans[x]);
        }
    }
}