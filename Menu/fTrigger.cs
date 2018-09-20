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
    public partial class fTrigger : Form
    {
        public fTrigger()
        {
            InitializeComponent();

            this.FormClosing += new FormClosingEventHandler(fTrigger_FormClosing);
        }

        private void fTrigger_Load(object sender, EventArgs e)
        {
            for(int i = 0; i < 255; i++)
                cbKey.Items.Add(Convert.ToString((Keys) i));

            for (int i = 0; i < 255; i++)
                cbEnable.Items.Add(Convert.ToString((Keys)i));

            ckDefault.Checked = Config.TriggerDefault;
            cbKey.SelectedIndex = Config.ToggleTrigger;
            cbEnable.SelectedIndex = Config.Trigger;
            tbDelay.Value = Config.TriggerDelay;

            lbDelay.Text = "Delay: " + tbDelay.Value + "ms";
        }

        private void fTrigger_FormClosing(object sender, EventArgs e)
        {
            Config.TriggerDefault = ckDefault.Checked;
            Config.ToggleTrigger = cbKey.SelectedIndex;
            Config.Trigger = cbEnable.SelectedIndex;
            Config.TriggerDelay = tbDelay.Value;
        }

        private void trackBar1_Scroll(object sender, System.EventArgs e)
        {
            lbDelay.Text = "Delay: " + tbDelay.Value + "ms";
        }
    }
}
