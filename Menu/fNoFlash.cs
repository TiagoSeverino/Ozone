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
    public partial class fNoFlash : Form
    {
        public fNoFlash()
        {
            InitializeComponent();

            this.FormClosing += new FormClosingEventHandler(fNoFlash_FormClosing);
        }

        private void fNoFlash_Load(object sender, EventArgs e)
        {
            for(int i = 0; i < 255; i++)
                cbKey.Items.Add(Convert.ToString((Keys) i));

            ckDefault.Checked = Config.NoFlashDefault;
            cbKey.SelectedIndex = Config.ToggleNoFlash;
            tbPercentage.Value = Config.FlashPercentage;

            lbPercentage.Text = "Percentage: " + tbPercentage.Value + "%";
        }

        private void fNoFlash_FormClosing(object sender, EventArgs e)
        {
            Config.NoFlashDefault = ckDefault.Checked;
            Config.ToggleNoFlash = cbKey.SelectedIndex;
            Config.FlashPercentage = tbPercentage.Value;
        }

        private void trackBar1_Scroll(object sender, System.EventArgs e)
        {
            lbPercentage.Text = "Percentage: " + tbPercentage.Value + "%";
        }
    }
}
