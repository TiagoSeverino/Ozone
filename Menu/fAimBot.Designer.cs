namespace Menu
{
    partial class fAimBot
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(fAimBot));
            this.ckDefault = new System.Windows.Forms.CheckBox();
            this.cbKey = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.tbSmooth = new System.Windows.Forms.TrackBar();
            this.lbSmooth = new System.Windows.Forms.Label();
            this.lbFOV = new System.Windows.Forms.Label();
            this.tbFOV = new System.Windows.Forms.TrackBar();
            this.rbHead = new System.Windows.Forms.RadioButton();
            this.rbBody = new System.Windows.Forms.RadioButton();
            this.label2 = new System.Windows.Forms.Label();
            this.ckMagnet = new System.Windows.Forms.CheckBox();
            ((System.ComponentModel.ISupportInitialize)(this.tbSmooth)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tbFOV)).BeginInit();
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
            // tbSmooth
            // 
            this.tbSmooth.LargeChange = 20;
            this.tbSmooth.Location = new System.Drawing.Point(112, 93);
            this.tbSmooth.Maximum = 100;
            this.tbSmooth.Name = "tbSmooth";
            this.tbSmooth.Size = new System.Drawing.Size(92, 45);
            this.tbSmooth.SmallChange = 10;
            this.tbSmooth.TabIndex = 1;
            this.tbSmooth.TickFrequency = 25;
            this.tbSmooth.Scroll += new System.EventHandler(this.trackBar1_Scroll);
            // 
            // lbSmooth
            // 
            this.lbSmooth.AutoSize = true;
            this.lbSmooth.Location = new System.Drawing.Point(12, 102);
            this.lbSmooth.Name = "lbSmooth";
            this.lbSmooth.Size = new System.Drawing.Size(75, 13);
            this.lbSmooth.TabIndex = 4;
            this.lbSmooth.Text = "Smooth: 100%";
            // 
            // lbFOV
            // 
            this.lbFOV.AutoSize = true;
            this.lbFOV.Location = new System.Drawing.Point(12, 141);
            this.lbFOV.Name = "lbFOV";
            this.lbFOV.Size = new System.Drawing.Size(60, 13);
            this.lbFOV.TabIndex = 6;
            this.lbFOV.Text = "FOV: 100%";
            // 
            // tbFOV
            // 
            this.tbFOV.LargeChange = 20;
            this.tbFOV.Location = new System.Drawing.Point(112, 132);
            this.tbFOV.Maximum = 100;
            this.tbFOV.Name = "tbFOV";
            this.tbFOV.Size = new System.Drawing.Size(92, 45);
            this.tbFOV.SmallChange = 10;
            this.tbFOV.TabIndex = 5;
            this.tbFOV.TickFrequency = 25;
            this.tbFOV.Scroll += new System.EventHandler(this.trackBar2_Scroll);
            // 
            // rbHead
            // 
            this.rbHead.AutoSize = true;
            this.rbHead.Location = new System.Drawing.Point(57, 64);
            this.rbHead.Name = "rbHead";
            this.rbHead.Size = new System.Drawing.Size(51, 17);
            this.rbHead.TabIndex = 7;
            this.rbHead.TabStop = true;
            this.rbHead.Text = "Head";
            this.rbHead.UseVisualStyleBackColor = true;
            // 
            // rbBody
            // 
            this.rbBody.AutoSize = true;
            this.rbBody.Location = new System.Drawing.Point(114, 64);
            this.rbBody.Name = "rbBody";
            this.rbBody.Size = new System.Drawing.Size(49, 17);
            this.rbBody.TabIndex = 8;
            this.rbBody.TabStop = true;
            this.rbBody.Text = "Body";
            this.rbBody.UseVisualStyleBackColor = true;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 66);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(39, 13);
            this.label2.TabIndex = 9;
            this.label2.Text = "Aim to:";
            // 
            // ckMagnet
            // 
            this.ckMagnet.AutoSize = true;
            this.ckMagnet.Location = new System.Drawing.Point(120, 12);
            this.ckMagnet.Name = "ckMagnet";
            this.ckMagnet.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.ckMagnet.Size = new System.Drawing.Size(82, 17);
            this.ckMagnet.TabIndex = 10;
            this.ckMagnet.Text = "Magnet Aim";
            this.ckMagnet.UseVisualStyleBackColor = true;
            // 
            // fAimBot
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(216, 180);
            this.Controls.Add(this.ckMagnet);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.rbBody);
            this.Controls.Add(this.rbHead);
            this.Controls.Add(this.lbFOV);
            this.Controls.Add(this.tbFOV);
            this.Controls.Add(this.lbSmooth);
            this.Controls.Add(this.tbSmooth);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.cbKey);
            this.Controls.Add(this.ckDefault);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "fAimBot";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "D0minator.xyz | Aimbot";
            this.Load += new System.EventHandler(this.fAimBot_Load);
            ((System.ComponentModel.ISupportInitialize)(this.tbSmooth)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tbFOV)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.CheckBox ckDefault;
        private System.Windows.Forms.ComboBox cbKey;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TrackBar tbSmooth;
        private System.Windows.Forms.Label lbSmooth;
        private System.Windows.Forms.Label lbFOV;
        private System.Windows.Forms.TrackBar tbFOV;
        private System.Windows.Forms.RadioButton rbHead;
        private System.Windows.Forms.RadioButton rbBody;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.CheckBox ckMagnet;
    }
}