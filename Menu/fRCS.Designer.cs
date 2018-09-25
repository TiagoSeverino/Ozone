namespace Menu
{
    partial class fRCS
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(fRCS));
            this.ckDefault = new System.Windows.Forms.CheckBox();
            this.cbKey = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.tbHorizontal = new System.Windows.Forms.TrackBar();
            this.lbHorizontal = new System.Windows.Forms.Label();
            this.lbVertical = new System.Windows.Forms.Label();
            this.tbVertical = new System.Windows.Forms.TrackBar();
            ((System.ComponentModel.ISupportInitialize)(this.tbHorizontal)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tbVertical)).BeginInit();
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
            // tbHorizontal
            // 
            this.tbHorizontal.LargeChange = 20;
            this.tbHorizontal.Location = new System.Drawing.Point(112, 62);
            this.tbHorizontal.Maximum = 100;
            this.tbHorizontal.Name = "tbHorizontal";
            this.tbHorizontal.Size = new System.Drawing.Size(92, 45);
            this.tbHorizontal.SmallChange = 10;
            this.tbHorizontal.TabIndex = 1;
            this.tbHorizontal.TickFrequency = 25;
            this.tbHorizontal.Scroll += new System.EventHandler(this.trackBar1_Scroll);
            // 
            // lbHorizontal
            // 
            this.lbHorizontal.AutoSize = true;
            this.lbHorizontal.Location = new System.Drawing.Point(12, 71);
            this.lbHorizontal.Name = "lbHorizontal";
            this.lbHorizontal.Size = new System.Drawing.Size(94, 13);
            this.lbHorizontal.TabIndex = 4;
            this.lbHorizontal.Text = "Percentage: 100%";
            // 
            // lbVertical
            // 
            this.lbVertical.AutoSize = true;
            this.lbVertical.Location = new System.Drawing.Point(12, 110);
            this.lbVertical.Name = "lbVertical";
            this.lbVertical.Size = new System.Drawing.Size(94, 13);
            this.lbVertical.TabIndex = 6;
            this.lbVertical.Text = "Percentage: 100%";
            // 
            // tbVertical
            // 
            this.tbVertical.LargeChange = 20;
            this.tbVertical.Location = new System.Drawing.Point(112, 101);
            this.tbVertical.Maximum = 100;
            this.tbVertical.Name = "tbVertical";
            this.tbVertical.Size = new System.Drawing.Size(92, 45);
            this.tbVertical.SmallChange = 10;
            this.tbVertical.TabIndex = 5;
            this.tbVertical.TickFrequency = 25;
            this.tbVertical.Scroll += new System.EventHandler(this.trackBar2_Scroll);
            // 
            // fRCS
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(216, 147);
            this.Controls.Add(this.lbVertical);
            this.Controls.Add(this.tbVertical);
            this.Controls.Add(this.lbHorizontal);
            this.Controls.Add(this.tbHorizontal);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.cbKey);
            this.Controls.Add(this.ckDefault);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "fRCS";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "D0minator.xyz | No Recoil";
            this.Load += new System.EventHandler(this.fRCS_Load);
            ((System.ComponentModel.ISupportInitialize)(this.tbHorizontal)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tbVertical)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.CheckBox ckDefault;
        private System.Windows.Forms.ComboBox cbKey;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TrackBar tbHorizontal;
        private System.Windows.Forms.Label lbHorizontal;
        private System.Windows.Forms.Label lbVertical;
        private System.Windows.Forms.TrackBar tbVertical;
    }
}