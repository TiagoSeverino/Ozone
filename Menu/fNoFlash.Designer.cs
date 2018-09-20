namespace Menu
{
    partial class fNoFlash
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(fNoFlash));
            this.ckDefault = new System.Windows.Forms.CheckBox();
            this.cbKey = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.tbPercentage = new System.Windows.Forms.TrackBar();
            this.lbPercentage = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.tbPercentage)).BeginInit();
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
            // tbPercentage
            // 
            this.tbPercentage.LargeChange = 20;
            this.tbPercentage.Location = new System.Drawing.Point(112, 62);
            this.tbPercentage.Maximum = 100;
            this.tbPercentage.Name = "tbPercentage";
            this.tbPercentage.Size = new System.Drawing.Size(92, 45);
            this.tbPercentage.SmallChange = 10;
            this.tbPercentage.TabIndex = 1;
            this.tbPercentage.TickFrequency = 25;
            this.tbPercentage.Scroll += new System.EventHandler(this.trackBar1_Scroll);
            // 
            // lbPercentage
            // 
            this.lbPercentage.AutoSize = true;
            this.lbPercentage.Location = new System.Drawing.Point(12, 71);
            this.lbPercentage.Name = "lbPercentage";
            this.lbPercentage.Size = new System.Drawing.Size(94, 13);
            this.lbPercentage.TabIndex = 4;
            this.lbPercentage.Text = "Percentage: 100%";
            // 
            // fNoFlash
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(216, 117);
            this.Controls.Add(this.lbPercentage);
            this.Controls.Add(this.tbPercentage);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.cbKey);
            this.Controls.Add(this.ckDefault);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "fNoFlash";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "D0minator.xyz | No Flash";
            this.Load += new System.EventHandler(this.fNoFlash_Load);
            ((System.ComponentModel.ISupportInitialize)(this.tbPercentage)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.CheckBox ckDefault;
        private System.Windows.Forms.ComboBox cbKey;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TrackBar tbPercentage;
        private System.Windows.Forms.Label lbPercentage;
    }
}