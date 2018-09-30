using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Threading;

namespace Menu
{
    public partial class fMenu : Form
    {
        string path = @"C:\D0minator\config.cfg";
        public fMenu()
        {
            InitializeComponent();
        }

        private void fMenu_Load(object sender, EventArgs e)
        {
            if (!Directory.Exists(@"C:\D0minator\"))
                Directory.CreateDirectory(@"C:\D0minator\");

            if (File.Exists(path))
                Config.ArrayToConfig(File.ReadAllLines(path));
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            File.Delete(path);
            File.WriteAllLines(path, Config.ConfigToArray());
            Environment.Exit(0);
        }

        private void btnWH_Click(object sender, EventArgs e)
        {
            fWH f = new fWH();
            f.ShowDialog();
        }

        private void btnRadar_Click(object sender, EventArgs e)
        {
            fRadar f = new fRadar();
            f.ShowDialog();
        }

        private void btnBHOP_Click(object sender, EventArgs e)
        {
            fBHOP f = new fBHOP();
            f.ShowDialog();
        }

        private void btnNoFlash_Click(object sender, EventArgs e)
        {
            fNoFlash f = new fNoFlash();
            f.ShowDialog();
        }

        private void btnTrigger_Click(object sender, EventArgs e)
        {
            fTrigger f = new fTrigger();
            f.ShowDialog();
        }

        private void btnMic_Click(object sender, EventArgs e)
        {
            fMisc f = new fMisc();
            f.ShowDialog();
        }

        private void btnRCS_Click(object sender, EventArgs e)
        {
            fRCS f = new fRCS();
            f.ShowDialog();
        }

        private void btnAimbot_Click(object sender, EventArgs e)
        {
            fAimBot f = new fAimBot();
            f.ShowDialog();
        }
    }
}
