/********************************************************************************
 *                                                                              *
 *        Licensa de Cópia (C) <2021>  <Corporação do Trabalho Binário>         *
 *                                                                              *
 *     Este  programa  é software livre: você pode redistribuir isto e/ou       *
 *     modificar  isto sobre os termos do  GNU Licensa Geral Pública como       8
 *     publicado  pela Fundação  de Software  Livre, tanto a versão 3  da       *
 *     Licensa, ou (dependendo da sua opção) qualquer versão posterior.         *
 *                                                                              *
 *     Este  programa é distribuído na  esperança que isto vai  ser útil,       *
 *     mas SEM  QUALQUER GARANTIA; sem  até mesmo a implicada garantia de       *
 *     COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a             *
 *     Licensa Geral Pública para mais detalhes.                                *
 *                                                                              *
 *     Você deve ter recebido uma  cópia da LICENSA GERAL PUBLICA e a GNU       *
 *     Licensa Pública Menor junto com este programa                            *
 *     Se não, veja <http://www.gnu.org/licenses/>.                             *
 *                                                                              *
 *     Suporte: https://nomade.sourceforge.io/                                  *
 *                                                                              *
 ********************************************************************************
 
      E-mails:                                                                 
      maria@arsoftware.net.br                                                  
      pedro@locacaodiaria.com.br                                               

 ********************************************************************************
 *                                                                              *
 *     contato imediato(para uma resposta muito rápida) WhatsApp                *
 *     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                 *      
 *                                                                              *
 *******************************************************************************/

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
