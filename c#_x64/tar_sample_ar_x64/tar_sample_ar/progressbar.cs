   /*
    Copyright (C) <2021>  <BinaryWork Corp.>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU GENERAL PUBLIC LICENSE
        and GNU LESSER GENERAL PUBLIC LICENSE along with this program.
        If not, see <http://www.gnu.org/licenses/>.

    support: https://arsoftware.net.br/binarywork _____________
    mirror :  http://nomade.sourceforge.net/?AR=true&ar_debug=1 <link dead>

        direct programmers e-mails:
        Ricardo: arsoftware25@gmail.com  ricardo@arsoftware.net.br
         Amanda: arsoftware10@gmail.com  amanda@arsoftware.net. br

        immediate contact(for a very fast answer) WhatsApp
        (+55)41 9627 1708 - it is always on
 */

using System;
using System.ComponentModel;
using System.Windows.Forms;

namespace AmandarRicardo_Koci_Progress
{
    public partial class progressbar : UserControl
    {
        public int Maximum
        {          
            get
            {
                return (int)max;
            }
            set
            {
                max = (double)value;
            }
        }
        [Description("This event will return new mouse information")]
        public event NewMouseEvent Mouse;
        public delegate void NewMouseEvent(ExtendedMouseEvent e);
        double
        getvalf(double maxa, double porr)
        {
            maxa = (maxa / 100.0) * porr;
            return maxa;
        }
        double
        getporf(double maxa, double fatiaa)
        {
            if (maxa == 0 || fatiaa == 0)//avoid division by zero
            {
                return 0;
            }
            maxa = ((double)100 / maxa * fatiaa);
            return maxa;
        }
        private double max = 10000.0;
        private double value_b = 0.0;
        public progressbar()
        {
            
            InitializeComponent();

        }
        private void progressbar_Load(object sender, EventArgs e)
        {
            deslizante.Left = 0;
            //deslizante.Top = 0;
            deslizante.Width = 0;
            deslizante.Height = 3;
            fixo.Left = 0;
            fixo.Top = 0;
            fixo.Width = this.Width;
            fixo.Height = this.Height;
            double a = fixo.Height;
            double b=3;
            a = (a - b) / 2.0;
            deslizante.Top = (int)a;
        }
        private void progressbar_Resize(object sender, EventArgs e)
        {
            deslizante.Left = 0;
            //deslizante.Top = 0;
            deslizante.Width = 0;
            deslizante.Height = 3;
            fixo.Left = 0;
            fixo.Top = 0;
            fixo.Width = this.Width;
            fixo.Height = this.Height;
            double a = fixo.Height;
            double b = 3;
            a = (a - b) / 2.0;
            deslizante.Top = (int)a;
        }

        private void deslizante_MouseDown(object sender, MouseEventArgs e)
        {
            ExtendedMouseEvent morcego = new ExtendedMouseEvent();
            double maximum = max * (double)this.Width;
            double position = max * (double)e.X;
            double val = getporf(maximum, position);
            val = getvalf(max, val);
            if (val > max)
            {
                val = max;
            }
            if (val < 0)
            {
                val = 0;
            }
            morcego.Value = (int)val;
            if (null != Mouse)
            {
                Mouse.Invoke(morcego);
            }
        }

        private void fixo_MouseDown(object sender, MouseEventArgs e)
        {
            ExtendedMouseEvent morcego = new ExtendedMouseEvent();
            double maximum = max * (double)this.Width;
            double position = max * (double)e.X;
            double val = getporf(maximum, position);
            val = getvalf(max, val);
            if (val > max)
            {
                val = max;
            }
            if (val < 0)
            {
                val = 0;
            }
            morcego.Value = (int)val;
            if (null != Mouse)
            {
                Mouse.Invoke(morcego);
            }
        }

        private void progressbar_MouseDown(object sender, MouseEventArgs e)
        {
            ExtendedMouseEvent morcego = new ExtendedMouseEvent();
            double maximum = max * (double)this.Width;
            double position = max * (double)e.X;
            double val = getporf(maximum, position);
            val = getvalf(max, val);
            if (val > max)
            {
                val = max;
            }
            if (val < 0)
            {
                val = 0;
            }
            morcego.Value = (int)val;
            if (null != Mouse)
            {
                Mouse.Invoke(morcego);
            }
        }

        private void deslizante_Click(object sender, EventArgs e)
        {

        }
        public System.Drawing.Color SetProgressColor
        {
        	set
        	{
        		this.deslizante.BackColor = value;
        	}
        }
        /// <summary>
        /// It  will set or get the progressbar value
        /// </summary>
        [Description("It will set the value on the progressbar")]
        public int Value
        {
            get
            {
                return (int)value_b;
            }
            set
            {
                double temp;
                value_b = value;
                if (value_b > max)
                {
                    value_b = (max);
                }
                if (value_b < 0)
                {
                    value_b = 0;
                }
                temp = getporf(max, value_b);
                temp = getvalf(this.Width, temp);
                deslizante.Width = (int)temp;        
            }
        }
        public class ExtendedMouseEvent
        {            
            public int Value=0;           
        }

        private void deslizante_MouseEnter(object sender, EventArgs e)
        {
            progressbar_MouseEnter(null, null);
        }

        private void fixo_MouseEnter(object sender, EventArgs e)
        {
            progressbar_MouseEnter(null, null);
        }

        private void progressbar_MouseEnter(object sender, EventArgs e)
        {            
            //MP3.disabled = true;
        }

        private void fixo_MouseLeave(object sender, EventArgs e)
        {            
            //MP3.disabled = false;
        }
    }
}
