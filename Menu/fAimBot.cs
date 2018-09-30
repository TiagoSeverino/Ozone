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
    public partial class fAimBot : Form
    {
        public fAimBot()
        {
            InitializeComponent();

            this.FormClosing += new FormClosingEventHandler(fAimBot_FormClosing);
        }

        private void fAimBot_Load(object sender, EventArgs e)
        {
            for(int i = 0; i < 255; i++)
                cbKey.Items.Add(Convert.ToString((Keys) i));

            ckDefault.Checked = Config.AimBotDefault;
            cbKey.SelectedIndex = Config.ToggleAimbot;
            tbSmooth.Value = Config.AimbotSmooth;
            tbFOV.Value = Config.AimbotFOV;

            rbBody.Checked = Config.AimbotBone == 5;
            rbHead.Checked = Config.AimbotBone == 8;

            lbSmooth.Text = "Smooth: " + tbSmooth.Value + "%";
            lbFOV.Text = "FOV: " + tbFOV.Value;
        }

        private void fAimBot_FormClosing(object sender, EventArgs e)
        {
            Config.AimBotDefault = ckDefault.Checked;
            Config.ToggleAimbot = cbKey.SelectedIndex;
            Config.AimbotSmooth = tbSmooth.Value;
            Config.AimbotFOV = tbFOV.Value;
            Config.AimbotBone = rbHead.Checked ? 8 : 5;
    }

        private void trackBar1_Scroll(object sender, System.EventArgs e)
        {
            lbSmooth.Text = "Smooth: " + tbSmooth.Value + "%";
        }

        private void trackBar2_Scroll(object sender, System.EventArgs e)
        {
            lbFOV.Text = "FOV: " + tbFOV.Value;
        }
    }
}
