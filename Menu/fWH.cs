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
    public partial class fWH : Form
    {
        public fWH()
        {
            InitializeComponent();

            this.FormClosing += new FormClosingEventHandler(fWH_FormClosing);
        }

        private void fWH_Load(object sender, EventArgs e)
        {
            for(int i = 0; i < 255; i++)
                cbKey.Items.Add(Convert.ToString((Keys) i));

            ckDefault.Checked = Config.WHDefault;
            cbKey.SelectedIndex = Config.ToggleWH;
        }

        private void fWH_FormClosing(object sender, EventArgs e)
        {
            Config.WHDefault = ckDefault.Checked;
            Config.ToggleWH = cbKey.SelectedIndex;
        }
    }
}
