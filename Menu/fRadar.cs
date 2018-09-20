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
    public partial class fRadar : Form
    {
        public fRadar()
        {
            InitializeComponent();

            this.FormClosing += new FormClosingEventHandler(fRadar_FormClosing);
        }

        private void fRadar_Load(object sender, EventArgs e)
        {
            for(int i = 0; i < 255; i++)
                cbKey.Items.Add(Convert.ToString((Keys) i));

            ckDefault.Checked = Config.RadarDefault;
            cbKey.SelectedIndex = Config.ToggleRadar;
        }

        private void fRadar_FormClosing(object sender, EventArgs e)
        {
            Config.RadarDefault = ckDefault.Checked;
            Config.ToggleRadar = cbKey.SelectedIndex;
        }
    }
}
