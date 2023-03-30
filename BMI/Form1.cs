using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Reflection.Emit;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace BMI
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
        }

        private void button1_Click(object sender, EventArgs e)
        {
            float h = Convert.ToInt32(height.Text);
            float m = Convert.ToInt32(wight.Text);
            h = Convert.ToInt32(h / 100);
            float bmi = m / (h * h);
            X.Text = Convert.ToString(bmi);

            if (bmi <= 18.5){ 
                label1.Text = "Недостаточный вес"; 
            }
            else if (bmi > 18.5 && bmi <= 24.9){
                label1.Text = "Нормальный вес"; 
            }
            else if (bmi > 24.9 && bmi <= 29.9){
                label1.Text = "Избыточный вес";
            }
            else if(bmi > 35) { 
                label1.Text = "Ожирение"; 
            }

            if (bmi < 50) { 
                trackBar1.Value = Convert.ToInt32(bmi); 
            }
            else { 
                trackBar1.Value = 50; 
            }

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }


        private void button2_Click(object sender, EventArgs e)
        {

        }
    }
}
