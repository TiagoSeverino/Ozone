using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Menu
{
    public partial class fRCS : Form
    {
        public fRCS()
        {
            InitializeComponent();

            this.FormClosing += new FormClosingEventHandler(fRCS_FormClosing);
        }

        private void fRCS_Load(object sender, EventArgs e)
        {
            for(int i = 0; i < 255; i++)
                cbKey.Items.Add(Convert.ToString((Keys) i));

            ckDefault.Checked = Config.RCSDefault;
            cbKey.SelectedIndex = Config.ToggleRCS;
            tbHorizontal.Value = Config.RcsHorizontalSmooth;
            tbVertical.Value = Config.RcsVerticalSmooth;

            lbHorizontal.Text = "Horizontal: " + tbHorizontal.Value + "%";
            lbVertical.Text = "Vertical: " + tbVertical.Value + "%";
        }

        private void fRCS_FormClosing(object sender, EventArgs e)
        {
            Config.RCSDefault = ckDefault.Checked;
            Config.ToggleRCS = cbKey.SelectedIndex;
            Config.RcsHorizontalSmooth = tbHorizontal.Value;
            Config.RcsVerticalSmooth = tbVertical.Value;
        }

        private void trackBar1_Scroll(object sender, System.EventArgs e)
        {
            lbHorizontal.Text = "Horizontal: " + tbHorizontal.Value + "%";
        }

        private void trackBar2_Scroll(object sender, System.EventArgs e)
        {
            lbVertical.Text = "Vertical: " + tbVertical.Value + "%";
        }
    }
}
