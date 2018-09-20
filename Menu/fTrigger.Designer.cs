namespace Menu
{
    partial class fTrigger
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(fTrigger));
            this.ckDefault = new System.Windows.Forms.CheckBox();
            this.cbKey = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.tbDelay = new System.Windows.Forms.TrackBar();
            this.lbDelay = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.cbEnable = new System.Windows.Forms.ComboBox();
            ((System.ComponentModel.ISupportInitialize)(this.tbDelay)).BeginInit();
            this.SuspendLayout();
            // 
            // ckDefault
            // 
            this.ckDefault.AutoSize = true;
            this.ckDefault.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.ckDefault.Location = new System.Drawing.Point(12, 12);
            this.ckDefault.Name = "ckDefault";
            this.ckDefault.Size = new System.Drawing.Size(102, 17);
            this.ckDefault.TabIndex = 0;
            this.ckDefault.Text = "Default (On/Off)";
            this.ckDefault.UseVisualStyleBackColor = true;
            // 
            // cbKey
            // 
            this.cbKey.FormattingEnabled = true;
            this.cbKey.Location = new System.Drawing.Point(79, 35);
            this.cbKey.Name = "cbKey";
            this.cbKey.Size = new System.Drawing.Size(121, 21);
            this.cbKey.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 38);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(61, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Toggle Key";
            // 
            // tbDelay
            // 
            this.tbDelay.LargeChange = 20;
            this.tbDelay.Location = new System.Drawing.Point(89, 91);
            this.tbDelay.Maximum = 150;
            this.tbDelay.Name = "tbDelay";
            this.tbDelay.Size = new System.Drawing.Size(115, 45);
            this.tbDelay.SmallChange = 10;
            this.tbDelay.TabIndex = 1;
            this.tbDelay.TickFrequency = 25;
            this.tbDelay.Scroll += new System.EventHandler(this.trackBar1_Scroll);
            // 
            // lbDelay
            // 
            this.lbDelay.AutoSize = true;
            this.lbDelay.Location = new System.Drawing.Point(12, 100);
            this.lbDelay.Name = "lbDelay";
            this.lbDelay.Size = new System.Drawing.Size(71, 13);
            this.lbDelay.TabIndex = 4;
            this.lbDelay.Text = "Delay: 100ms";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 65);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(61, 13);
            this.label2.TabIndex = 6;
            this.label2.Text = "Enable Key";
            // 
            // cbEnable
            // 
            this.cbEnable.FormattingEnabled = true;
            this.cbEnable.Location = new System.Drawing.Point(79, 62);
            this.cbEnable.Name = "cbEnable";
            this.cbEnable.Size = new System.Drawing.Size(121, 21);
            this.cbEnable.TabIndex = 5;
            // 
            // fTrigger
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(216, 138);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.cbEnable);
            this.Controls.Add(this.lbDelay);
            this.Controls.Add(this.tbDelay);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.cbKey);
            this.Controls.Add(this.ckDefault);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "fTrigger";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "D0minator.xyz | Trigger Bot";
            this.Load += new System.EventHandler(this.fTrigger_Load);
            ((System.ComponentModel.ISupportInitialize)(this.tbDelay)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.CheckBox ckDefault;
        private System.Windows.Forms.ComboBox cbKey;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TrackBar tbDelay;
        private System.Windows.Forms.Label lbDelay;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox cbEnable;
    }
}