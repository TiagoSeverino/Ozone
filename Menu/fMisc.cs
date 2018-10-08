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
    public partial class fMisc : Form
    {
        public fMisc()
        {
            InitializeComponent();

            this.FormClosing += new FormClosingEventHandler(fMisc_FormClosing);
        }

        private void fMisc_Load(object sender, EventArgs e)
        {
            for(int i = 0; i < 255; i++){
                cbRankReveal.Items.Add(Convert.ToString((Keys) i));
                cbExitKey.Items.Add(Convert.ToString((Keys)i));
            }

            cbExitKey.SelectedIndex = Config.Exit;
            cbRankReveal.SelectedIndex = Config.RankReveal;
        }

        private void fMisc_FormClosing(object sender, EventArgs e)
        {
            Config.Exit = cbExitKey.SelectedIndex;
            Config.RankReveal = cbRankReveal.SelectedIndex;
        }
    }
}
