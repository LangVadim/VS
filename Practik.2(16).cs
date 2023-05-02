using System;
class HelloWorld {
    static void Main() {
        int b, c, d;
        double a, m, Z;
    
        b = Convert.ToInt32(Console.ReadLine());
        c = Convert.ToInt32(Console.ReadLine());
        d = Convert.ToInt32(Console.ReadLine());
    
        if (b >= 5)
        {
            a = b * b;
        }
        else
        {
            a = b * b * Math.Cos(b);
        }
    
        if (c == d)
        {
            m = c + d * d;
        }
        else
        {
            m = c * d * Math.Cos(d);
        }
    
        Z = (a * Math.Cos(a) + m) / (c + a);
        
        Console.WriteLine(Z);
    }
}
