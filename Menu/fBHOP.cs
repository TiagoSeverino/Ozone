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
    public partial class fBHOP : Form
    {
        public fBHOP()
        {
            InitializeComponent();

            this.FormClosing += new FormClosingEventHandler(fBHOP_FormClosing);
        }

        private void fBHOP_Load(object sender, EventArgs e)
        {
            for(int i = 0; i < 255; i++)
                cbKey.Items.Add(Convert.ToString((Keys) i));

            ckDefault.Checked = Config.BHopDefault;
            cbKey.SelectedIndex = Config.ToggleBHop;
        }

        private void fBHOP_FormClosing(object sender, EventArgs e)
        {
            Config.BHopDefault = ckDefault.Checked;
            Config.ToggleBHop = cbKey.SelectedIndex;
        }
    }
}
