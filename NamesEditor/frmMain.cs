using SimulationCore.Resources;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace NamesEditor
{
    public partial class frmMain : Form
    {
        private string _targetFileName;
        private bool _isDirty;
        private NamesFileResource _resourceFile = new NamesFileResource();

        public frmMain()
        {
            InitializeComponent();

            newEditor();
        }

        private void newEditor()
        {
            _targetFileName = "";
            _isDirty = false;
            _resourceFile = new NamesFileResource();

            clearEditor();
        }

        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            newEditor();
        }

        private void clearEditor()
        {
            lstNames.Items.Clear();
            txtName.Text = "";
            checkButtonsStates();
        }

        private void txtName_TextChanged(object sender, EventArgs e)
        {
            checkButtonsStates();
        }

        private void checkButtonsStates()
        {
            btnUpdate.Enabled = lstNames.SelectedIndex >= 0 && lstNames.Items.Count > 0;
            btnDelete.Enabled = lstNames.SelectedIndex >= 0 && lstNames.Items.Count > 0;
            btnClear.Enabled = lstNames.Items.Count > 0;
            btnAdd.Enabled = txtName.Text.Trim().Length > 0;
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            clearEditor();

            _isDirty = true;
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            int curSel = lstNames.SelectedIndex;
            if (curSel >= 0)
            {
                lstNames.Items.RemoveAt(curSel);
                _isDirty = true;
            }
            checkButtonsStates();
        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            int curSel = lstNames.SelectedIndex;
            if (curSel >= 0)
            {
                lstNames.Items[curSel] = txtName.Text;
                _isDirty = true;
            }
            checkButtonsStates();
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            if (lstNames.Items.Contains(txtName.Text))
            {
                MessageBox.Show("This name is already exists..", "Simulation Names Editor");                
            }
            else
            {
                lstNames.Items.Add(txtName.Text);
                _isDirty = true;
            }            
            txtName.Text = "";
            checkButtonsStates();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void saveEditor(bool force = false)
        {
            if (!force && _isDirty && _targetFileName != "")
            {
                _resourceFile.Save(_targetFileName);
                _isDirty = false;
            }
            else
            {
                if (saveFileDialog.ShowDialog() == DialogResult.OK)
                {
                    _resourceFile = new NamesFileResource();
                    _targetFileName = saveFileDialog.FileName;
                    foreach (var obj in lstNames.Items)
                    {
                        string name = obj as string;
                        _resourceFile.AddName(name);
                    }
                    _resourceFile.Save(_targetFileName);
                    _isDirty = false;
                }
            }
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            saveEditor(false);
        }

        private void saveAsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            saveEditor(true);
        }

        private void loadEditor()
        {
            if (_isDirty)
                saveEditor(false);

            _resourceFile = new NamesFileResource();
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                _targetFileName = openFileDialog.FileName;
                _resourceFile.Load(_targetFileName);
                _isDirty = false;

                lstNames.Items.Clear();
                foreach(var name in _resourceFile.Names)
                    lstNames.Items.Add(name);
            }
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            loadEditor();
        }
    }
}
