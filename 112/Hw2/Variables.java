//L G
//3/15/10
/*PSEUDOCODE:
Store 1 in the variable amount.
Store 50 in the variable m.
Store 10 in the variable n.
Store 5 in the variable p.
Store n / p + 3 in the variable a.
Store m / p + n - 10 * amount in the variable b.
Store m - 3 * n + 4 * amount in the variable c.
Store amount / 5 in the variable d.
Store 18 / p in the variable e.
Store 18 % p in the variable f.
Store -p * n in the variable g.
Store -m / 20 in the variable h.
Store -m % 20 in the variable i.
Store (m + n) / (p + amount) in the variable j.
Store m + n / p + amount in the variable k.
Display the values of a through k on different lines on the screen.*/
public class Variables
{

	public static void main (String [] args)
	{
	int amount,m,n,p,a,b,c;
	amount = 1;
	m = 50;
	n = 10;
	p = 5;
	int d,e,f,g,h,i,j,k;
	a = n / p + 3;
	b = m / p + n - 10 * amount;
	c = m - 3 * n + 4 * amount;
	d = amount / 5;
	e = 18 / p;
	f = 18 % p;
	g = -p * n;
	h = -m / 20;
	i = -m % 20;
	j = (m + n) / (p + amount);
	k = m + n / p + amount;

	System.out.println("a) " + a);
	System.out.println("b) " + b);
	System.out.println("c) " + c);
	System.out.println("d) " + d);
	System.out.println("e) " + e);
	System.out.println("f) " + f);
	System.out.println("g) " + g);
	System.out.println("h) " + h);
	System.out.println("i) " + i);
	System.out.println("j) " + j);
	System.out.println("k) " + k);

	}

}
